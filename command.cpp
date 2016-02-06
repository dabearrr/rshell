#include "command.h"
Command::Command(string n) {
	commandName = n;
}
Command::Command(string n, vector<string> a) {
	commandName = n;

	args.resize(a.size());	
	for(int i = 0; i < a.size(); i++) {
		args.at(i) = a.at(i);
	}
}

bool Command::exec() {
	char* evp[] = {const_cast<char*>( commandName.c_str() ), (char*) 0 };
        execvp( const_cast<char*>( commandName.c_str() ) , evp);
}	
