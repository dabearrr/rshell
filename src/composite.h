//"Composite.h"
#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "base.h"

class Composite : public Base 
{
        protected:
        bool firstCommand;
	Base* secondCommand;
	bool executedTruely;

        public:
        //Composite(bool a, Base* b) { firstCommand = a; secondCommand = b; }
	//bool exec();
        //void print();
	bool getExecuted() { return executedTruely; }
};

#endif //COMPOSITE_H

