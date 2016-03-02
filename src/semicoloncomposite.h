#ifndef SEMICOLONCOMPOSITE_H 
#define SEMICOLONCOMPOSITE_H

class SemiColonComposite : public Composite
{
        public:
        SemiColonComposite(bool a, Base* b) { firstCommand = a; secondCommand = b; }
        bool exec() {
                return secondCommand->exec();
        }
};

#endif //SEMICOLONCOMPOSITE_H



