#ifndef __FACTORY_MASTER_HPP__
#define __FACTORY_MASTER_HPP__

#include "base.hpp"
class Base;

class Factory_master {
    public:
        /*pure virtual function */
        virtual Base* parse(char** input, int length) = 0;       
};

#endif //__FACTORY_MASTER_HPP__
