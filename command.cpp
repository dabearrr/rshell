#include "command.h"
Command::Command() {
	commandName = "";
}
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
Command::Command(const Command &c) {
	commandName = c.getName();
}	
bool Command::exec() {	
	/*char* evp[] = {const_cast<char*>( commandName.c_str() ), (char*) 0 };
        execvp( const_cast<char*>( commandName.c_str() ) , evp);*/
	cout << " executing!" << commandName << endl;
	// insert exec code here!
	
	//assuming it executed correctly
	data = true;
	return true;
}
void Command::rearg(vector <string> &v) {
	args.clear();
	for(int i = 0; i < v.size(); i++) {
		args.push_back(v.at(i));
	}
}

void Command::print() {
	cout << "Command Name: " << commandName << endl;
	cout << "Vector of Arguments: " << endl;
	for (int i = 0; i < args.size(); i++) {
		cout << args.at(i) << " ";
	}
	cout << endl;
}
	
