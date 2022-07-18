#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include "math.h"
using namespace std;

class Abs : public Decorator
{
    public:
        /* Constructors */
        Abs(Base *orig): Decorator(orig) { };

		/* evaluate virtual function*/ 
		double evaluate(){
			return abs(Temp_base->evaluate());
		};
};

#endif //__ABS_HPP__

