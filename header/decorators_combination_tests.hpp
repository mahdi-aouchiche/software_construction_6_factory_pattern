#ifndef __DECORATORS_COMBINATION_TEST_HPP__
#define __DECORATORS_COMBINATION_TEST_HPP__

#include "gtest/gtest.h"
#include "headers.hpp"	
	
/* Operands */
Base* _ten      = new Op(-10);
Base* _eight    = new Op(-8);    
Base* _five     = new Op(-5);
Base* _half     = new Op(-0.5);
Base* zero      = new Op(0);
Base* half	= new Op(0.5);
Base* one       = new Op(2);
Base* three     = new Op(3);    
Base* PI        = new Op(3.14);
Base* four	= new Op(4);
Base* seven     = new Op(7);
Base* ten_half  = new Op(10.5);      
	
TEST(Decorators_Combination, Ceil_Floor) {
    Base* mult     = new Mult(PI, four);	
    Base* minus    = new Sub(three, half);
    Floor* branch1 = new Floor(minus);
    Add* tree	   = new Add(mult, branch1);
    Ceil* test	   = new Ceil(tree);
    
    EXPECT_EQ(test->evaluate(), 15);
}

TEST(Decorators_Combination, Ceil_Abs) {
    Base* mult   = new Mult( PI , four);
    Base* minus  = new Sub(_five, half);
    Abs* branch1 = new Abs(minus);
    Add* tree    = new Add(mult, branch1);
    Ceil* test   = new Ceil(tree);

    EXPECT_EQ(test->evaluate(), 19);
}

TEST(Decorators_Combination, Ceil_Trunc) {

    Base* mult     = new Mult( PI , four);
    Base* minus    = new Sub(_five, half);
    Trunc* branch1 = new Trunc(minus);
    Add* tree      = new Add(mult, branch1);
    Ceil* test     = new Ceil(tree);

    EXPECT_EQ(test->evaluate(), 8);
    EXPECT_EQ(test->stringify(), "3.140000 * 4.000000 + -5.500000" );
}

TEST(Decorators_Combination, Ceil_Paren) {
    Base* mult     = new Mult( PI , four);
    Base* minus    = new Sub(_five, half);
    Paren* branch1 = new Paren(minus);
    Add* tree      = new Add(mult, branch1);
    Ceil* test     = new Ceil(tree);

    EXPECT_EQ(test->evaluate(), 8);
    EXPECT_EQ(test->stringify(), "3.140000 * 4.000000 + (-5.000000 - 0.500000)" );
}

TEST(Decorators_Combination, Floor_Ceil) {
    Base* mult    = new Mult(PI, four);
    Base* minus   = new Sub(three, half);
    Ceil* branch1 = new Ceil(minus);
    Add* tree     = new Add(mult, branch1);
    Floor* test   = new Floor(tree);

    EXPECT_EQ(test->evaluate(), 15);
}

TEST(Decorators_Combination, Floor_Abs) {
    Base* mult   = new Mult(PI, four);
    Base* minus  = new Sub(_five, half);
    Abs* branch1 = new Abs(minus);
    Add* tree    = new Add(mult, branch1);
    Floor* test  = new Floor(tree);

    EXPECT_EQ(test->evaluate(), 18 );
}

TEST(Decorators_Combination, Floor_Trunc) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Trunc* branch1 = new Trunc(minus);
    Add* tree      = new Add(mult, branch1);
    Floor* test    = new Floor(tree);

    EXPECT_EQ(test->evaluate(), 7 );
    EXPECT_EQ(test->stringify(), "3.140000 * 4.000000 + -5.500000" );
}

TEST(Decorators_Combination, Floor_Paren) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Paren* branch1 = new Paren(minus);
    Add* tree      = new Add(mult, branch1);
    Floor* test    = new Floor(tree);

    EXPECT_EQ(test->evaluate(), 7 );
    EXPECT_EQ(test->stringify(), "3.140000 * 4.000000 + (-5.000000 - 0.500000)" );
}

TEST(Decorators_Combination, Abs_Ceil) {
    Base* mult    = new Mult(PI, four);
    Base* minus   = new Sub(_five, half);
    Ceil* branch1 = new Ceil(minus);
    Add* tree     = new Add(mult, branch1);
    Abs* test     = new Abs(tree);

    EXPECT_NEAR(test->evaluate(), 7.56, 0.01);
}

TEST(Decorators_Combination, Abs_Floor) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Floor* branch1 = new Floor(minus);
    Add* tree      = new Add(mult, branch1);
    Abs* test      = new Abs(tree);

    EXPECT_NEAR(test->evaluate(), 6.56, 0.01);
}


TEST(Decorators_Combination, Abs_Trunc) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Trunc* branch1 = new Trunc(minus);
    Add* tree      = new Add(mult, branch1);
    Abs* test      = new Abs(tree);

    EXPECT_NEAR(test->evaluate(), 7.06, 0.01);
    EXPECT_EQ(test->stringify(), "3.140000 * 4.000000 + -5.500000");
}

TEST(Decorators_Combination, Abs_Paren) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Paren* branch1 = new Paren(minus);
    Add* tree      = new Add(mult, branch1);
    Abs* test      = new Abs(tree);
 
    EXPECT_DOUBLE_EQ(test->evaluate(), 7.06);
    EXPECT_EQ(test->stringify(), "3.140000 * 4.000000 + (-5.000000 - 0.500000)");	
}	

TEST(Decorators_Combination, Trunc_Ceil) {
    Base* mult    = new Mult(PI, four);
    Base* minus   = new Sub(_five, half);
    Ceil* branch1 = new Ceil(minus);
    Add* tree     = new Add(mult, branch1);
    Trunc* test   = new Trunc(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 7.56);
    EXPECT_EQ(test->stringify(), "7.560000");
}

TEST(Decorators_Combination, Trunc_Floor) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Floor* branch1 = new Floor(minus);
    Add* tree      = new Add(mult, branch1);
    Trunc* test    = new Trunc(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 6.56);
    EXPECT_EQ(test->stringify(), "6.560000" );
}

TEST(Decorators_Combination, Trunc_Abs) {
    Base* mult   = new Mult(PI, four);
    Base* minus  = new Sub(_five, half);
    Abs* branch1 = new Abs(minus);
    Add* tree    = new Add(mult, branch1);
    Trunc* test  = new Trunc(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 18.06);
    EXPECT_EQ(test->stringify(), "18.060000");
}

TEST(Decorators_Combination, Trunc_Paren) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Paren* branch1 = new Paren(minus);
    Add* tree      = new Add(mult, branch1);
    Trunc* test    = new Trunc(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 7.06);
    EXPECT_EQ(test->stringify(), "7.060000");
}

TEST(Decorators_Combination, Paren_Ceil) {
    Base* mult    = new Mult(PI, four);
    Base* minus   = new Sub(_five, half);
    Ceil* branch1 = new Ceil(minus);
    Add* tree     = new Add(mult, branch1);
    Paren* test   = new Paren(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 7.56);
    EXPECT_EQ(test->stringify(), "(3.140000 * 4.000000 + -5.000000 - 0.500000)");
}

TEST(Decorators_Combination, Paren_Floor) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Floor* branch1 = new Floor(minus);
    Add* tree      = new Add(mult, branch1);
    Paren* test    = new Paren(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 6.56);
    EXPECT_EQ(test->stringify(), "(3.140000 * 4.000000 + -5.000000 - 0.500000)");
}

TEST(Decorators_Combination, Paren_Abs) {
    Base* mult   = new Mult(PI, four);
    Base* minus  = new Sub(_five, half);
    Abs* branch1 = new Abs(minus);
    Add* tree    = new Add(mult, branch1);
    Paren* test  = new Paren(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 18.06);
    EXPECT_EQ(test->stringify(), "(3.140000 * 4.000000 + -5.000000 - 0.500000)");
}

TEST(Decorators_Combination, Paren_Trunc) {
    Base* mult     = new Mult(PI, four);
    Base* minus    = new Sub(_five, half);
    Trunc* branch1 = new Trunc(minus);
    Add* tree      = new Add(mult, branch1);
    Paren* test    = new Paren(tree);

    EXPECT_DOUBLE_EQ(test->evaluate(), 7.06);
    EXPECT_EQ(test->stringify(), "(3.140000 * 4.000000 + -5.500000)");
}

#endif	// __DECORATORS_COMBINATION_TEST_HPP__
