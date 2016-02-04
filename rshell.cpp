#include "rshell.h"
using namespace std;
Rshell::Rshell() {
	userInput = "not written to yet*";
	username = getlogin();
	int temp = gethostname(hostname, 100);
	if(temp == -1) {
		cout << "error finding hostname ";
	}
}
void Rshell::prompt() {
	cout << username;
	cout << "@";
	cout << hostname;
	cout << "$";
}
void Rshell::terminal() {
	while(1) {
		prompt();
		parse();
	}
}
void Rshell::parse() {
	getline(cin, userInput);
	cout << userInput << endl;
}
/*
int main() {
	Rshell commandLine;
	commandLine.prompt();	
	return 0;
}*/

