#ifndef RSHELL_H
#define RSHELL_H

#include <unistd.h>
#include <iostream>
class Rshell
{
        private:
	char hostname[100];
	char* username;
        public:
        Rshell();
        void terminal();
        void prompt();
        //void parse();
};

#endif //PAYLOAD_STATUS_H

