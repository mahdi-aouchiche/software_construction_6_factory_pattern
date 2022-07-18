#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include "math.h"
using namespace std;

class Floor : public Decorator
{
    public:
        /* Constructors */
        Floor(Base *orig): Decorator(orig) {};

		/*Implement the evaluate virtual function */
		double evaluate(){
			return floor(Temp_base->evaluate());
		}
};

#endif //__FLOOR_HPP__