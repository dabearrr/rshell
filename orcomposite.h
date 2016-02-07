#ifndef ORCOMPOSITE_H
#define ORCOMPOSITE_H

class OrComposite : public Composite
{
        public:
        OrComposite(bool a, Base* b) { firstCommand = a; secondCommand = b; }
        bool exec() {
                if(!firstCommand) {
                        return secondCommand->exec();
                }
                else {
                        return false;
                }
        }
};

#endif //ORCOMPOSITE_H



