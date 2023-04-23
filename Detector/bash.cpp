#include <bits/stdc++.h>
using namespace std;
int main () {  
	string str = "ps -e | grep keylogger";

	const char *command = str.c_str();

	cout << command << endl;
	system(command);

    cout << "killing keylogger....";
    system("killall keylogger");

	return 0;
}