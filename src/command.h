//"Command.h"
#ifndef COMMAND_H
#define COMMAND_H

#include "base.h"
#include <sys/wait.h>
#include <errno.h>
#include <cstdio>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

class Command : public Base
{
	private:
	bool data;
	//string name;
	//string commandName;
	vector<string> args;	

	public:
	Command();
	//Command(string n);
	//Command(string n, vector<string> a);
	//Command(const Command& c);
	Command(vector<string> &v);
	bool exec();	
	//void rename(string n){commandName = n;}
	//string getName() const {return commandName;}
	void rearg(vector <string> &v);
	void appendargs(string s) {args.push_back(s);}
	void print();
};

#endif //COMMAND_H
