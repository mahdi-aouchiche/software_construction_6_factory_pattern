#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include "base.hpp"
#include "decorator.hpp"
#include <string>
#include "math.h"

using namespace std;
class Ceil : public Decorator 
{
    public:
        /* Constructors */
        Ceil(Base *orig): Decorator(orig) { };
        
        /* Implement the evaluate function to return the ceiling value */
        double evaluate(){
                return ceil(Temp_base -> evaluate());
        }
};

#endif //__CEIL_HPP__


