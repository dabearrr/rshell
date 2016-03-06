#ifndef SEMICOLONCOMPOSITE_H 
#define SEMICOLONCOMPOSITE_H

class SemiColonComposite : public Composite
{
        public:
        SemiColonComposite(bool a, Base* b) { firstCommand = a; secondCommand = b; }
        bool exec() {
		bool TempBoolean = secondCommand->exec();
                if(TempBoolean && firstCommand) {
			executedTruely = true;
		}
		else {
			executedTruely = false;
		}
		return executedTruely;
        }
};

#endif //SEMICOLONCOMPOSITE_H



