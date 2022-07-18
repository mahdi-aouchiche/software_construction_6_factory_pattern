#ifndef __MAIN_LAB6_CPP
#define __MAIN_LAB6_CPP

#include "../header/headers.hpp"

int main(int argc, char** argv) {
    Factory_master* test =  new FactoryExpressionTree();
    Base* output = test->parse(++argv, --argc);  
    
    if (output != nullptr){ 
    	cout << output->stringify() << " = " << output->evaluate() << endl;
    }

    return 0;
}

#endif // __MAIN_LAB6_CPP