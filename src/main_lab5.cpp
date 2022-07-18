#ifndef __MAIN_LAB5_CPP
#define __MAIN_LAB5_CPP

#include "../header/headers.hpp"

int main() {
    Op* three = new Op(3);
    Op* seven = new Op(7);
    Op* pi = new Op(3.14);
    Op* two_n = new Op(-2);
    Mult* mult = new Mult(seven, pi);
    Add* add = new Add(three, mult);
    Sub* minus = new Sub(add, two_n);

    cout << "Ceil of pi test:\t\t";
    Ceil* test_pi = new Ceil(pi);
    cout << test_pi->evaluate() << "\t"<< test_pi->stringify() << "\n";

    cout << "Floor of pi in equation:\t";
    Floor* F_pi = new Floor(pi);
    Mult* f_pi_7 = new Mult(F_pi, seven);
    cout << f_pi_7->evaluate() << "\t"<< f_pi_7->stringify() << "\n";

    cout <<  "Abs test of neg number:\t\t";
    Abs* a_two_n = new Abs(two_n);
    Sub* a_minus = new Sub(add, two_n);
    cout << a_minus->evaluate() << "\t"<< a_minus->stringify() << "\n";


    cout << "Trunc test of exp:\t\t";
    Trunc* t_add = new Trunc(add);
    Sub* t_minus = new Sub(t_add, two_n);
    cout << t_minus->evaluate() << "\t"<< t_minus->stringify() << "\n";

    cout << "Paren test of exp:\t\t";
    Paren* p_add = new Paren(add);
    Sub* p_minus = new Sub(p_add, two_n);
    cout << p_minus->evaluate() << "\t"<< p_minus->stringify() << "\n";
    
    return 0;
}

#endif // __MAIN_LAB5_CPP