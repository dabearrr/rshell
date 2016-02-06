//"Command.h"
#ifndef COMMAND_H
#define COMMAND_H

#include "base.h"

class Command : public Base
{
	private:
	bool data;
	string name;
	string commandName;
	vector<string> args;	

	public:
	Command(string n);
	Command(string n, vector<string> a);
	bool exec();	

};

#endif //COMMAND_H
