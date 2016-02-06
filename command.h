//"Command.h"
#ifndef COMMAND_H
#define COMMAND_H

#include "base.h"
#include <string>

class Command : public Base
{
	private:
	bool data;
	string name;

	public:
	void exec();	

};

#endif //COMMAND_H
