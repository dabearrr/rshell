//"Rshell.h"
#ifndef RSHELL_H
#define RSHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/scoped_ptr.hpp>
#include "command.h"
#include "composite.h"
#include "orcomposite.h"
#include "andcomposite.h"
#include "semicoloncomposite.h"

using namespace std;
class Rshell
{
    private:
    string userInput;
    char hostname[100];
    char* username;
    vector<string> userTokens;       
    vector<string> userCommands;
    vector<string> userComposites;
    vector<Base*> commands;
    vector<Composite*> composites;
    vector<Base*> executables;
    bool executeString(string execString);

    public:
    Rshell();
    void terminal();
    void prompt();
    void parse();
};

#endif //RSHELL_H

