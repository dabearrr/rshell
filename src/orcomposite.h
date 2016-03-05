#ifndef ORCOMPOSITE_H
#define ORCOMPOSITE_H

class OrComposite : public Composite
{
        public:
        OrComposite(bool a, Base* b) { firstCommand = a; secondCommand = b; }
        bool exec() {
                if(!firstCommand) {
                        bool TempBoolean = secondCommand->exec();
			if(TempBoolean) {
				executedTruely = true;
			}
			else {
				executedTruely = false;
			}
                }
                else {
                        //return false;
			executedTruely = true;
                }
		return executedTruely;
        }
};

#endif //ORCOMPOSITE_H



