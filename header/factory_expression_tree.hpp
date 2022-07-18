#ifndef __FACTORY_EXPRESSION_TREE_HPP__
#define __FACTORY_EXPRESSION_TREE_HPP__

#include "headers.hpp"

class FactoryExpressionTree : public Factory_master 
{
	public: 
	virtual Base* parse(char** input, int length) {
        			
        /* Correct tree will have a multiple of 3 inputs
          (2 operands and one operation to perform)    
		*/
        if (length % 2 == 0){
			cout << "Not the correct amount of inputs" << endl;
			return nullptr;
		}	

        double d = 0; 
		char* pEnd;	

		for (int i = 0; i < length; i = i + 2){
			d = strtod(input[i], &pEnd);
			if (*pEnd != 0)	{
				cout << "Not a double input: " << input[i] << endl;
				return nullptr;
			}
		}
		
        /* strtod() parses the C-string str interpreting its content as a floating point number
           (according to the current locale) and returns its value as a double
        */
        d = strtod(input[0], &pEnd);	
		Base* output = new Op(d);

		for (int i = 1; i < length; i = i + 2) {
			d = strtod(input[i+1], &pEnd);	
			Base* out_2 = new Op(d);
			string test = input[i];

            // create an op node for the input   
			if (test ==  "+") {          // addition
				output = new Add(output, out_2);

			} else if (test ==  "-") {   // subtraction
                output = new Sub(output, out_2);

            } else if (test ==  "/") {   // division
                output = new Div(output, out_2);

            } else if (test ==  "*") {   // multiplication
                output = new Mult(output, out_2);

            } else if (test ==  "**") {  // power 
                output = new Pow(output, out_2);

            } else {    // wrong operation as default
				cout << "Wrong operator: " << input [i] << endl;
				return nullptr;
			}
		}
		
        return output;
    };
};

#endif //__FACTORY_EXPRESSION_TREE_HPP__
