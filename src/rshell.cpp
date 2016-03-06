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

int deepestPar(string s) {
	int tempIndex = -1;
	for(unsigned int i = 0; i < s.size(); i++) {
		char tempC = s.at(i);
		if(tempC == '(') {
			tempIndex = i;
		}
	}
	return tempIndex;
}

string isolateDeep(string s, int &begin, int &end) {
	char tempChar = 'd';
	unsigned int i = 0 ;
	unsigned int lastParSeen = 999;
	while(i < s.size() && tempChar != ')') {
		tempChar = s.at(i);
		if(tempChar == '(') {
			lastParSeen = i;
		}
		if(tempChar == ')') {
			break;
		}
		i++;	
	}
	begin = lastParSeen;
	end = i;
	string tempS = s.substr(begin, (end - begin) + 1);
	//cout << begin << " " << end << " " << tempS << endl;
	//cout << s.at(end) << endl;
	return tempS;
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

bool Rshell::executeString(string execString) {
	string oldUserInput = userInput;
	userInput = execString;
    
	//chk empty
	if(userInput == "") {
		return true;
	}
	
	//remove comments
	userInput = userInput.substr(0, userInput.find('#', 0));
	
	string CHKCONNECTORINIT = userInput.substr(0, 2);
	if(CHKCONNECTORINIT == "&&" || CHKCONNECTORINIT == "||" 
	|| CHKCONNECTORINIT == "; " || CHKCONNECTORINIT == ";;") {
		return false;
	} 
	//cout << CHKCONNECTORINIT << endl;
	//return;
	
	//space out those dumb semicolons t.t
	for(unsigned int i = 0; i < userInput.size(); i++) {
		char temp = userInput.at(i);
		if(temp == ';') {
			userInput.insert(i, " ");
			i+= 2;
		}
	}
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
				return false;
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
		return false;
	}
	
	if(openParenthesis != closedParenthesis) {
		cout << "Error: unequal amt of closed/open parenthesis\n";
		return false;
	}
	testBrackets(userInput);
	


	//new code for parenthesis stack
	//
	//
	//
	//

	/*stack <string> parenStack;
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
						
	}*/	

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

	//chk if to manny connectors
	if(userComposites.size() >= userCommands.size()) {
		return false;
	}
	
	//used to execute singular commands
	//simply makes a base* to a command object and executes it
	bool TEMPBOOL = false;
	if(userComposites.empty()) {
		string s = userCommands.at(0);
		vector <string> temp;
		tokenizer< char_separator<char> > tempTokens(s, sep);
       		BOOST_FOREACH(string t, tempTokens) {
			temp.push_back(t);
	        }

		Base* element = new Command(temp);
		TEMPBOOL = element->exec();
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
				Composite* baseTemp = new AndComposite(firstRun,
				commands.at(i+1));
				composites.push_back(baseTemp);
			}
			else if(s == "||") {
				Composite* baseTemp = new OrComposite(firstRun, 
				commands.at(i+1));
				composites.push_back(baseTemp);
			}
			else {
				Composite* baseTemp = new SemiColonComposite(firstRun,
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
	if(composites.size() > 0) {
		TEMPBOOL = true;
		for(unsigned int i = 0; i < composites.size(); i++) {
			if(composites.at(i)->getExecuted() == true) {
				TEMPBOOL = false;
			}
		}
	}
	//lastly we clear our vectors for the next run
	userTokens.clear();
	userComposites.clear();
	userCommands.clear();
	commands.clear();
	composites.clear();	
	userInput = oldUserInput;
	return TEMPBOOL;
}
 
void Rshell::parse() {
	//take in input
	getline(cin, userInput);
	
	//chk empty
	if(userInput == "") {
		return;
	}
	
	//remove comments
	userInput = userInput.substr(0, userInput.find('#', 0));
	
	string CHKCONNECTORINIT = userInput.substr(0, 2);
	if(CHKCONNECTORINIT == "&&" || CHKCONNECTORINIT == "||" 
	|| CHKCONNECTORINIT == "; " || CHKCONNECTORINIT == ";;") {
		return;
	} 
	//cout << CHKCONNECTORINIT << endl;
	//return;
	
	//space out those dumb semicolons t.t
	for(unsigned int i = 0; i < userInput.size(); i++) {
		char temp = userInput.at(i);
		if(temp == ';') {
			userInput.insert(i, " ");
			i+= 2;
		}
	}
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
	if(openParenthesis == 0) {
		executeString(userInput);
	}
	else {
		//I WILL NEVER GIVE UP
		while(userInput.find("(") != string::npos) {
			int deepOpen = 0;
			int deepClosed = 0;
			bool execTrue = true;
			string execString = "";
			execString = isolateDeep(userInput, deepOpen, deepClosed);
			//cout << "****" << execString << "*****" << endl;
			//execString = execString.substr(1, execString.size() - 2);
			//cout << "****" << execString << "*****" << endl;
			
			int prevOpen = -1;
			int nextClosed = -1;
			for(int i = deepOpen - 1; i >= 0; i--) {
				char tempC = userInput.at(i);
				if(tempC == '(') {
					prevOpen = i;
					break;
				}
			}
			if(prevOpen != -1 && (execString.find("||") == string::npos && execString.find("&&")
			 == string::npos && execString.find(";") == string::npos) ) {
			bool seen = true;
			for(int i = deepClosed + 2; i < static_cast<int>(userInput.size()); i++) {
				char tempC = userInput.at(i);
				if(tempC == '(') {
					seen = false;
				}
				if(tempC == ')') {
					if(seen) {
						nextClosed = i;
						break;
					}
					seen = true; 
				}
			}
			string execString2 = userInput.substr(prevOpen, (nextClosed - prevOpen) + 1);
			cout << "*******" << execString2 << "********" <<  endl;
			//execString2 = execString2.substr(1, (execString2.size() - 1) - 1);
			execString2.erase(0, 1); execString2.erase(execString2.size() - 1, 1);
			cout << "Executing: " << execString2 << endl;
			execTrue = executeString(execString2);
			if(execTrue) {
				userInput.replace(prevOpen, (nextClosed - prevOpen) + 1, "true ");
			}
			else {
				userInput.replace(prevOpen, (nextClosed - prevOpen) + 1, "true ");
			}
			}
			else {
			//execute execString
			//assign exectrue to it's value
			execString.erase(0, 1); execString.erase(execString.size() - 1, 1);
			cout << "Executing: " << execString << endl;
			execTrue = executeString(execString);
			if(execTrue) {
				userInput.replace(deepOpen, (deepClosed - deepOpen) + 1, "true ");
			}
			else {
				userInput.replace(deepOpen, (deepClosed - deepOpen) + 1, "false ");
			}
			}
			cout << "Input is now: " << userInput << endl;
			
		}
		return;
	}
	
	
	//new code for parenthesis stack
	//
	//
	//
	//

	/*stack <string> parenStack;
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
						
	}*/	

	//
	//
	//
	//

	//lastly we clear our vectors for the next run
	userTokens.clear();
	userComposites.clear();
	userCommands.clear();
	commands.clear();
	composites.clear();	
}
