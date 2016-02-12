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
//PREPARE YOURSELF, A LOT OF JANK IS BELOW
//YOU GOT THIS DUDE
void Rshell::parse() {
	//take in input
	getline(cin, userInput);
	
	//remove comments
	userInput = userInput.substr(0, userInput.find('#', 0));
	//cout << "The input from the user, without comments is : " << userInput << endl;
	
	//boost lib usages
	char_separator<char> sep(" ");
	tokenizer< char_separator<char> > tokens(userInput, sep);
	//cout << "Tokenizer tokens: " << endl;
	/*BOOST_FOREACH(string t, tokens) {
		cout << t << endl;
	}*/

	//Command command = Command();
	//int boostIndex1 = 0;
	/*BOOST_FOREACH(string t, tokens) {
		if(boostIndex1 == 0) {
			command.rename(t);
		}
		else {
			command.appendargs(t);
		}
		boostIndex1++;	
	}*/
	 BOOST_FOREACH(string t, tokens) {
		userTokens.push_back(t);         	       
        }	
	string str = "";
	for(unsigned int i = 0; i < userTokens.size(); i++) {
		string comp = userTokens.at(i);
		if(comp != "||" && comp != "&&" && comp != ";") {
			str = str + " " + comp;
		}
		else {
			userCommands.push_back(str);
			if(comp == "||") {
				userComposites.push_back("||");
			}
			else if(comp == "&&") {
				userComposites.push_back(";");
			}
			else {
				userComposites.push_back("&&");
			}
			str = "";
		}
	}
	if(str != "") {
		userCommands.push_back(str);
		str = "";
	}
	/*for(int i = 0; i < userCommands.size(); i++) {
		cout << userCommands.at(i) <<  i << " ";
	}*/
	if(userComposites.empty()) {
		string s = userCommands.at(0);
		vector <string> temp;
		tokenizer< char_separator<char> > tempTokens(s, sep);
       		//cout << "Tokenizer tokens: " << endl;
       		BOOST_FOREACH(string t, tempTokens) {
        	        //cout << t << " ";
			temp.push_back(t);
	        }

		Base* element = new Command(temp);
		//executables.push_back(element);
		element->exec();
		//userCommands.clear();
		//temp.clear();
	}
	else {
		//create the array of commands
		vector <string> tempCommand;
		string s = "";
		for(unsigned int i = 0; i < userCommands.size(); i++) {
			s = userCommands.at(i);
			tokenizer< char_separator<char> > tempTokens(s, sep);
			BOOST_FOREACH(string t, tempTokens) {
                        	tempCommand.push_back(t);
			}
			Base* baseTemp = new Command(tempCommand);
			commands.push_back(baseTemp);
			tempCommand.clear();
                }
		//for(int i = 0; i < commands.size(); i++) {
		//	commands.at(i)->exec();
		//}
		bool firstRun = commands.at(0)->exec();
		for(unsigned int i = 0; i < userComposites.size(); i++) {
                        s = userComposites.at(i);
                        if(s == "&&") {
				Base* baseTemp = new AndComposite(firstRun, commands.at(i+1));
				composites.push_back(baseTemp);
			}
			else if(s == "||") {
				Base* baseTemp = new OrComposite(firstRun, commands.at(i+1));
				composites.push_back(baseTemp);
			}
			else {
				Base* baseTemp = new SemiColonComposite(firstRun, commands.at(i+1));
				composites.push_back(baseTemp);
			}
                        tempCommand.clear();
                }
		for(unsigned int i = 0; i < composites.size(); i++) {
			composites.at(i)->exec();
		}
	}
	userTokens.clear();
	userComposites.clear();
	userCommands.clear();
	commands.clear();
	composites.clear();	
	//command.print();
	//Base* executable = new Command(command);
	
	//We will localise the following in our exec() member of Command
	/*
	pid_t pID = fork();
	if(pID == 0) { //child
		cout << "Child Process " << endl;
			
		//execvp usage requires a const_cast<char*> of a cstr for arg1
		//and a char* array with the const_cast<char*> cstr and following arguments

		//this will call execvp on our command
		for(int i = 0; i < i.size(); i++) {
			executables.at(i)->exec();
		}
	}
	else if(pID < 0) {
		cout << "Fork failure" << endl;
		exit(1);
	}
	else {	//parent
		//waitPID(); << Need help implemeting this to wait for child to finish
		cout << "Parent does nothing" << endl;
	}
	*/
}
