//"Base.h"
#ifndef BASE_H
#define BASE_H

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/scoped_ptr.hpp>

using namespace std;

class Base
{
	private:

	public:
	virtual bool exec() = 0;
};
#endif //BASE_H
