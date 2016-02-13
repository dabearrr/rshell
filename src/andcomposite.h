//"andcomposite.h"
#ifndef ANDCOMPOSITE_H
#define ANDCOMPOSITE_H

class AndComposite : public Composite
{
        public:
        AndComposite(bool a, Base* b) { firstCommand = a; secondCommand = b; }
        bool exec() {
		if(firstCommand) {
			return secondCommand->exec();
		}
		else {
			return false;
		}
	}
};

#endif //ANDCOMPOSITE_H


