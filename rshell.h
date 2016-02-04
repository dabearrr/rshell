//"Rshell.h"
#ifndef RSHELL_H
#define RSHELL_H

#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;
class Rshell
{
    private:
    string userInput;
	char hostname[100];
	char* username;
        
	public:
    Rshell();
    void terminal();
    void prompt();
    void parse();
};

#endif //RSHELL_H

