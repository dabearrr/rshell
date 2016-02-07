#include "rshell.h"
using namespace std;
using namespace boost;
Rshell::Rshell() {
	//constructor will find the username and hostname
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
	cout << "$ ";
}
void Rshell::terminal() {
	//terminal will prompt then parse the input
	while(1) {
		prompt();
		parse();
	}
}
void Rshell::parse() {
	//take in input
	getline(cin, userInput);

	//boost lib usages
	char_separator<char> sep(" ");
	tokenizer< char_separator<char> > tokens(userInput, sep);
	/*cout << "Tokenizer tokens: " << endl;
	BOOST_FOREACH(string t, tokens) {
		cout << t << endl;
	}*/

	Command command = Command();
	int boostIndex1 = 0;
	BOOST_FOREACH(string t, tokens) {
		if(boostIndex1 == 0) {
			command.rename(t);
		}
		else {
			command.appendargs(t);
		}	
	}

	command.print();		

	pid_t pID = fork();
	if(pID == 0) { //child
		cout << "Child Process " << endl;
				
		//execvp usage requires a const_cast<char*> of a cstr for arg1
		//and a char* array with the const_cast<char*> cstr and following arguments
		char* evp[] = {const_cast<char*>( userInput.c_str() ), (char*) 0 };
		execvp( const_cast<char*>( userInput.c_str() ) , evp);
	}
	else if(pID < 0) {
		cout << "Fork failure" << endl;
		exit(1);
	}
	else {	//parent
		//waitPID(); << Need help implemeting this to wait for child to finish
		cout << "Parent does nothing" << endl;
	}
}

