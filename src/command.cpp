#include "command.h"

Command::Command(){}

Command::Command(vector <string> &v) {
	args = v;
}

bool Command::exec() {
	if(args.at(0) == "true") {
		return true;
	}
	if(args.at(0) == "false") {
		return false;
	}
	//exit command handling
	if(args.at(0) == "exit") {
		exit(1);
	}
	
	//test command handling
	//CONSIDER MOVING TO CHILD PROCESS
	if(args.at(0) == "test") {
		// Test Command Implementation
		//buf struct used to extract information about the given path
		//flag will hold our flag for test, if none given, then it is -e
		struct stat buf;
		string flag = "";

		//bools are used for our tests to hold if the path is the flag
		bool isDir = false;
		bool isReg = false;
		bool exists = false;

		//first check if a flag was specified
		//if it was, then our path will be in index 2, else 1
		//also checks for too many args
		if(args.size() == 2) {
			stat(const_cast<char*>(args.at(1).c_str()), &buf);
			flag = "-e";
		}
		else if(args.size() == 3) {
			stat(const_cast<char*>(args.at(2).c_str()), &buf);
			flag = args.at(1);
		}
		else {
			cout << "Error: Too many args for test!" << endl;
			return false;
		}
		
		//macros areused to determine if the path is a file or dir
		if(S_ISDIR(buf.st_mode)) {
			isDir = true;
		}
		if(S_ISREG(buf.st_mode)) {
			isReg = true;
		}
		if(isReg || isDir) {
			exists = true;
		}

		//test based on flag specified
		if(flag == "-e") {
			if(exists) {
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
		}
		else if(flag == "-f") {
			if(isReg) {
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
		}
		else if(flag == "-d") {
			if(isDir) {
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
		}
		else {
			cout << "Error: Incorrect flag specified" << endl;
			return false;
		}
		
		//just in case error handling should never happen
		cout << "Error: Drastic Test Failure" << endl;
		return false;
	}
	
	//we want to convert our vector of strings to an array of char*s
	//we use a neat little trick here, we create an vector of char*s
	//then, we convert each string from our orignal vector in cstrs
	//we const cast those cstrings into our vector of char*
	//here comes the trick: we access the underlying array by getting the
	//address of the first element!
	vector<char*> temp;
	for(unsigned int i = 0; i <args.size(); i++) {
		temp.push_back(const_cast<char*>(args.at(i).c_str()));
	}

	temp.push_back(NULL);
	char** argArray = &temp[0];
	
	//used to check for errors
	int status;
	
	//begin the forking!
	pid_t pID = fork();
	if(pID == 0) { //child
			
		//execvp usage requires a const_cast<char*> of a cstr for arg1
		//and a char* array with the const_cast<char*> cstr and following arguments
		execvp(argArray[0], argArray);
		if(-1 == execvp(argArray[0], argArray)) {
			perror("There was an error with execvp()");	
			exit(1);
		}
		exit(127);
	}	
	else if(pID < 0) {
		perror("There was an error with fork().");
		exit(1);
	}	
	else {	//parent
		//we wait	
		wait(&status);
		// we use wife excited to check for execvp errors
		if(WIFEXITED(status)) {
	        	if(WEXITSTATUS(status) == 0)
			{
				//program works
				return true;	
			}
			else
			{
				//program failed
				perror("There was an error with wait()");
				return false;
			}	
		}	
		else {return false;}
		//cout << endl;
		//cout << "Parent does nothing here and child process terminates woohoo! " << endl;
	}
	
	return false;
}

void Command::rearg(vector <string> &v) {
	args.clear();
	for(unsigned int i = 0; i < v.size(); i++) {
		args.push_back(v.at(i));
	}
}

void Command::print() {
	cout << "Vector of Arguments: " << endl;
	for (unsigned int i = 0; i < args.size(); i++) {
		cout << args.at(i) << " ";
	}
	cout << endl;
}
