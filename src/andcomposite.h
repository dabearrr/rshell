//"andcomposite.h"
#ifndef ANDCOMPOSITE_H
#define ANDCOMPOSITE_H

class AndComposite : public Composite
{
        public:
        AndComposite(bool a, Base* b) { firstCommand = a; secondCommand = b; }
        bool exec() {
		if(firstCommand) {
			bool TempBoolean = secondCommand->exec();
			if(TempBoolean && firstCommand) {
				executedTruely = true;
			}
			else {
				executedTruely = false;
			}
		}
		else {
			executedTruely = false;
		}
		return executedTruely;
	}
};

#endif //ANDCOMPOSITE_H


