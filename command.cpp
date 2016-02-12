#include "command.h"
#include <sys/wait.h>

Command::Command() {
	//nothing?
}
/*Command::Command(string n) {
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
}*/
Command::Command(vector <string> &v) {
	/*for(int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
		args.push_back(v.at(i));
	}*/
	args = v;
}

bool Command::exec() {	
	if(args.at(0) == "exit") {
		exit(1);
	}
	
	/*char* evp[] = {const_cast<char*>( commandName.c_str() ), (char*) 0 };
        execvp( const_cast<char*>( commandName.c_str() ) , evp);*/
        
	cout << "Executing: " << args.at(0) << endl;
	// insert exec code here!
	vector<char*> temp;
	for(int i = 0; i <args.size(); i++) {
		temp.push_back(const_cast<char*>(args.at(i).c_str()));
	}

	temp.push_back(NULL);
	char** argArray = &temp[0];
	int status;
	pid_t pID = fork();
	if(pID == 0) { //child
		cout << "Child Process here calling EXECVP" << endl;
			
		//execvp usage requires a const_cast<char*> of a cstr for arg1
		//and a char* array with the const_cast<char*> cstr and following arguments

		//this will call execvp on our command	
	 execvp(argArray[0], argArray);
		
	exit(127);
	}	
	else if(pID < 0) {
		cout << "Fork failure" << endl;
		exit(1);
	}

		
	else {	//parent
		
		wait(&status);
		if(WIFEXITED(status)){
	        	if(WEXITSTATUS(status) == 0)
			{
				//program works
				return true;	
			}
			else
			{
				//program failed
				return false;
			}	
	}	
		else
		{
			return false;}

		cout << endl;

		cout << "Parent does nothing here and child process terminates woohoo! " << endl;
	}
	
	//assuming it executed correctly
	return false;
}
void Command::rearg(vector <string> &v) {
	args.clear();
	for(int i = 0; i < v.size(); i++) {
		args.push_back(v.at(i));
	}
}

void Command::print() {
	//cout << "Command Name: " << commandName << endl;
	cout << "Vector of Arguments: " << endl;
	for (int i = 0; i < args.size(); i++) {
		cout << args.at(i) << " ";
	}
	cout << endl;
}
	
