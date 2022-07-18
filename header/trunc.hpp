#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include <string>
#include "math.h"
using namespace std;

class Trunc : public Decorator
{
    private:
	    double result; 

    public:
        /* Constructors */
        Trunc (Base *orig): Decorator(orig) 
        {	
		    this->result = orig->evaluate(); 
        }

        /*Implement the stringify function */
	    string stringify() {
		    return to_string(this->result);
	    } 	
};

#endif //__TRUNC_HPP__


