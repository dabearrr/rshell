#include "rshell.h"
#include <stack>
using namespace std;
using namespace boost;

vector<string> divideS(string t, const char* splitter) {
    char* tempS = new char[t.size() + 1];
    strcpy(tempS, t.c_str());
    tempS[t.size()] = '\0';
    char* c;
	c = strtok(tempS, splitter);
	vector<string> tokens;
	while(c != NULL) {
		string k(c);
		trim(k);
		tokens.push_back(k);
		c = strtok(NULL, splitter);
	}
	return tokens;
}
unsigned int getEPL(string uc, unsigned int loc) {
    unsigned int l = loc + 1;
    stack<char> t;
    t.push('b');
    char c = ')';
    char o = '(';
    for(; l < uc.size(); ++l) {
        if(uc.at(l) == o) {
            t.push(o);
        }
        else if(uc.at(l) == c) {
            char chk = t.top(); t.pop();
            if(chk == 'b' && t.empty()) {
                return l;
            }
        }
    }
    return l;
}

string rP(string s) {
    bool recurse = false;
    stack<char> p;
    
    do {
        trim(s);
        bool noP = (s.find('(') != 0);
        bool noPEnd = (getEPL(s, 0) == s.size() - 1);
        if(noP) {
            return s;
        }
        else if(noPEnd) {
            s.erase(0, 1);
            s.erase(s.size()-1);
            bool continueloop = (getEPL(s, 0) == s.size() - 1);
            if(continueloop) {
                recurse = true;
            }
            else {
                return s;
            }
        }
        else {
            return s;
        }
    } while(recurse);
    return s;
}


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

void filterP(string uc) {
	stack<char> t;
	for(unsigned int r = 0; r < uc.size(); r++) {
		if(uc.at(r) == '(') {
			t.push('(');
		}
		else if(uc.at(r) == ')') {
			if(t.empty()) {
				t.pop();
			}
			else {
				cout << "Not enough open Parenthesis" << endl;
				exit(0);
			}
		}
	}
	if(!t.empty()) {
		cout << "Not enough closing parenthesis" << endl;
		exit(0);
	}
}



class Super : public Base
{
    protected:
    vector<string> comps;
    vector<string> supers;
    vector<bool> didExec;
    string ui;
    unsigned int beginSuper;
    unsigned int endSuper;
    unsigned int andLoc, orLoc, semiLoc;
    int loc1, loc2;
    bool deeper;
    
    public:
    Super(string s) { ui = s; }
    bool exec() {
    	const char O = '('; const char A = '&'; const char OR = '|';
        const char S = ';'; const char SP = ' ';
        string AndComp = "&&"; string OrComp = "||";
        string SemiComp = ";";
        
        trim(ui);
        ui = rP(ui);
        
        if(ui == "") { return true; }
        deeper = false;
        for(unsigned int q = 0; q < ui.size(); q++) {
            char o = '(';
            bool d = ui.at(q) == o;
            if(d) { deeper = true; }
        }
        
        if(deeper == true) {
        	string superHold;
        	unsigned int r = 0; 
        	while(r < ui.size()) {
        		bool chk1 = ui.at(r) == O; bool chk2 = ui.at(r) == A; 
        		bool chk3 = ui.at(r) == OR; bool chk4 = ui.at(r) == S;
        		bool chk5 = ui.at(r) == SP;
        		if(chk1) {
        			beginSuper = r;
        			endSuper = getEPL(ui, r);
        			superHold = ui.substr(beginSuper, (endSuper - beginSuper) + 1);
        			supers.push_back(superHold);
        			r += (endSuper - beginSuper) + 1;
        		}
        		else if(chk2) {
        			bool ampChk = ui.at(r + 1) == A;
        			if(ampChk) { comps.push_back(AndComp); }
        			r += 2;
        		}
        		else if(chk3) {
        			bool orChk = ui.at(r + 1) == OR;
        			if(orChk) { comps.push_back(OrComp); }
        			r += 2;
        		}
        		else if(chk4) {
        			bool semiChk = ui.at(r + 1) == S;
        			if(semiChk) { comps.push_back(SemiComp); }
        			r += 2;
        		}
        		else if(chk5) {
        			++r;
        		}
        		else {
        			beginSuper = r;
        			unsigned int andLoc = ui.find(AndComp, r);
        			unsigned int orLoc = ui.find(OrComp, r);
        			unsigned int semiLoc = ui.find(SemiComp, r);
        			
        			// bool final1 = (andLoc == string::npos);
        			// bool final2 = (orLoc == string::npos);
        			// bool final3 = (semiLoc == string::npos);
        			// bool final = final1 && final2 && final3;
        			 if(ui.find(AndComp, r) == string::npos 
        			 && ui.find(OrComp, r) == string::npos 
        			 && ui.find(SemiComp, r) ) { 
        				endSuper = ui.size(); 
        			}
        			else {
        				bool alo = andLoc < orLoc; bool als = andLoc < semiLoc;
        				bool ola = orLoc < andLoc; bool ols = orLoc < semiLoc;
        				bool sla = semiLoc < andLoc; bool slo = semiLoc < orLoc;
        				if(alo && als) { endSuper = andLoc - 1; }
        				else if(ola && ols) { endSuper = orLoc - 1; }
        				else if(sla && slo) { endSuper = semiLoc - 1; }
        			}
        			superHold  = ui.substr(beginSuper, endSuper - beginSuper);
        			r = r + (endSuper - beginSuper);
        			supers.push_back(superHold);
        		}
        	}
        	//WHILE END
        	Base* initCommand = new Super(supers.at(0));
        	bool resultF = initCommand->exec();
        	
        	for(unsigned int q = 0; q < comps.size(); q++) {
        		Base* consec;
        		bool andCreate = comps.at(q) == "&&";
        		bool orCreate = comps.at(q) == "&&";
        		bool semiCreate = comps.at(q) == "&&";
        		
        		if(andCreate) { consec = new AndComposite(resultF, new Super(supers.at(q + 1))); }
        		else if(orCreate) { consec = new OrComposite(resultF, new Super(supers.at(q + 1))); }
        		else if(semiCreate) { consec = new SemiColonComposite(resultF, new Super(supers.at(q + 1))); }
        		
        		return consec->exec();
        	}
        }
        else if(!deeper) {
        	testBrackets(ui);
        	for(unsigned int r = 0; r < ui.length(); ++r) {
        		bool chk2 = ui.at(r) == A; bool chk3 = ui.at(r) == OR;
    			bool chk4 = ui.at(r) == S;
        	    if(chk2) {
        			bool ampChk = ui.at(r + 1) == A;
        			if(ampChk) { comps.push_back(AndComp); }
        			r += 2;
        		}
        		else if(chk3) {
        			bool orChk = ui.at(r + 1) == OR;
        			if(orChk) { comps.push_back(OrComp); }
        			r += 2;
        		}
        		else if(chk4) {
        			bool semiChk = ui.at(r + 1) == S;
        			if(semiChk) { comps.push_back(SemiComp); }
        			r += 2;
        		}
        	}
        	vector<string> leafs = divideS(ui, "||&&;");
        	
        	vector<string> initExec = divideS(leafs.at(0), " ");
        	Base* initLeaf = new Command(initExec);
        	bool initialize = initLeaf->exec();
        	didExec.push_back(initialize);
        	
        	for(unsigned int r = 0; r < comps.size(); ++r) {
        		Base* consec;
        		
        		vector<string> parameters = divideS(leafs.at(r + 1), " ");
        		bool chk1 = comps.at(r) == AndComp;
        		bool chk2 = comps.at(r) == OrComp;
        		bool chk3 = comps.at(r) == SemiComp;
        		if(chk1) {
        			consec = new AndComposite(initialize, new Command(parameters));
        		}
        		else if(chk2) {
        			consec = new OrComposite(initialize, new Command(parameters));
        		}
        		else if(chk3) {
        			consec = new SemiColonComposite(initialize, new Command(parameters));
        		}
        		bool following = consec->exec();
        		didExec.push_back(following);
        	}
        	bool trueSuper = false;
        	for(unsigned int q = 0; q < didExec.size(); q++) {
        		if(didExec.at(q)) {
        			trueSuper = true;
        		}
        	}
        	return trueSuper;
        }
        comps.clear();
        supers.clear();
        return false;
    }
};
	
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
			if(composites.at(i)->getExecuted() == false) {
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
	trim(userInput);
	
	//We create our main super to run
	//userInput.insert(0, "(");
	//userInput.insert(userInput.size() - 1, ")");
	filterP(userInput);
	Base* SuperExecutable = new Super(userInput);
	SuperExecutable->exec();

	//lastly we clear our vectors for the next run
	userTokens.clear();
	userComposites.clear();
	userCommands.clear();
	commands.clear();
	composites.clear();	
}
