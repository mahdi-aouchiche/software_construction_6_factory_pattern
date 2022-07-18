#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include <string>
using namespace std;

class Paren : public Decorator
{
    public:
        /* Constructors */
        Paren(Base *orig): Decorator(orig) { };
	
        /* virtual function*/
        string stringify(){
		    return "(" + Temp_base->stringify() + ")";
	    };
};

#endif //__PAREN_HPP__
