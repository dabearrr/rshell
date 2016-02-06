//"Rshell.h"
#ifndef RSHELL_H
#define RSHELL_H

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/scoped_ptr.hpp>
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

