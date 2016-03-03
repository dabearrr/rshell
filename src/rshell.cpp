#include "rshell.h"
#include <stack>
using namespace std;
using namespace boost;

void testBrackets(string &s) {
	string tempTest = "test ";
	while(s.find('[') != string::npos) {
		int tmpPos = s.find('[');
		s.erase(tmpPos, 1);
		s.insert(tmpPos, tempTest);
		tmpPos = s.find(']');
		s.erase(tmpPos, 1);
	}
}

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
	//simply prompts the user
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
	
	//remove comments
	userInput = userInput.substr(0, userInput.find('#', 0));
	
	//Bracket handling to rewrite as test
	int openBrackets = 0;
	int closedBrackets = 0;
	int openParenthesis = 0;
	int closedParenthesis = 0;

	//for brackets, cannot be nested
	bool seenOpen = false;

	for(unsigned int i = 0; i < userInput.size(); i++) {
		char temp = userInput.at(i);
		if(temp == '[') {
			openBrackets++;
			if(seenOpen) {
				cout << "Error: Another Open Bracket b4 closed";
				cout << endl;
				return;
			}
			seenOpen = true;
		}
		else if(temp == ']') {
			closedBrackets++;
			seenOpen = false;
		}
		else if(temp == '(') {
			openParenthesis++;
		}
		else if (temp == ')') {
			closedParenthesis++;
		}
	}
	if(openBrackets != closedBrackets) {
		cout << "Error: Not enough brackets (unequal)" << endl;
		return;
	}
	
	if(openParenthesis != closedParenthesis) {
		cout << "Error: unequal amt of closed/open parenthesis\n";
		return;
	}
	testBrackets(userInput);
	


	//new code for parenthesis stack
	//
	//
	//
	//

	stack <string> parenStack;
	string temp = "";
	unsigned int j = 0;
	for(j=j; j < userInput.size(); j++)
	{
		char parenCheck = userInput.at(j); 
		if(parenCheck == '(')
		{	while(userInput.at(j) != ')')
			{	j++;
				temp.push_back(userInput.at(j));
			}
			parenStack.push(temp);
			temp.clear();
		}
		else
		{
			//do normal commands without parenthesis
		}
						
	}	

	//
	//
	//
	//
	

	//boost lib usages
	//we want to sepate the input into tokens
	char_separator<char> sep(" ");
	tokenizer< char_separator<char> > tokens(userInput, sep);
	
	BOOST_FOREACH(string t, tokens) {
		userTokens.push_back(t);         	       
        }	
	
	//with these tokens, we will separate the commands and composites
	//into their own string, in order to create the actual objects
	//str is used as a temp to store the commands as we get each arg
	//for it
	string str = "";
	for(unsigned int i = 0; i < userTokens.size(); i++) {
		//comp holds the single current token
		string comp = userTokens.at(i);

		//if the token is a composite, then we have reached the end of
		//our command, and we pull push the command string to a vector
		//and the specific type of composite to another vector
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
	//used to execute singular commands
	//simply makes a base* to a command object and executes it
	if(userComposites.empty()) {
		string s = userCommands.at(0);
		vector <string> temp;
		tokenizer< char_separator<char> > tempTokens(s, sep);
       		BOOST_FOREACH(string t, tempTokens) {
			temp.push_back(t);
	        }

		Base* element = new Command(temp);
		element->exec();
	}
	else {
		//create the array of command objects from the command strings
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

		//the first command always executes, and is used in composite
		//object creation
		bool firstRun = commands.at(0)->exec();
	
		//create our vector of composites
		for(unsigned int i = 0; i < userComposites.size(); i++) {
                        s = userComposites.at(i);
                        if(s == "&&") {
				Base* baseTemp = new AndComposite(firstRun,
				commands.at(i+1));
				composites.push_back(baseTemp);
			}
			else if(s == "||") {
				Base* baseTemp = new OrComposite(firstRun, 
				commands.at(i+1));
				composites.push_back(baseTemp);
			}
			else {
				Base* baseTemp = new SemiColonComposite(firstRun,
				commands.at(i+1));
				composites.push_back(baseTemp);
			}
                        tempCommand.clear();
                }
		//now just execute our vector of composite objects
		for(unsigned int i = 0; i < composites.size(); i++) {
			composites.at(i)->exec();
		}
	}
	//lastly we clear our vectors for the next run
	userTokens.clear();
	userComposites.clear();
	userCommands.clear();
	commands.clear();
	composites.clear();	
}
