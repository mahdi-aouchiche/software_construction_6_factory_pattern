#ifndef __FACTORY_EXPRESSION_TREE_UNIT_TEST_HPP__
#define __FACTORY_EXPRESSION_TREE_UNIT_TEST_HPP__

#include "gtest/gtest.h"
#include "headers.hpp"

TEST(FactoryExpressionTree, addition) {
	char* test[3];	        // initialize a char pointer array 	
	test[0] = (char*)"2.5";	// left operand = 2.5
	test[1] = (char*)"+";   // addition operation
 	test[2] = (char*)"10";	// right operand = 10	
		
	// Create a new factory object to call the parse function
	Factory_master* factory =  new FactoryExpressionTree();	
    // Call the parse function	
	Base* add = factory->parse(test, 3); 
	
	ASSERT_NE(add, nullptr);
	EXPECT_EQ(add->stringify(), "2.500000 + 10.000000");
	EXPECT_EQ(add->evaluate(), 12.5); 
}

TEST(FactoryExpressionTree, multiplication) {
    char* test[3];            // initialize a char pointer array
    test[0] = (char*) "2.5";  // left operand = 2.5
    test[1] = (char*) "*";    // multiplication operation
    test[2] = (char*) "10";   // right operand = 10

    // Create a factory object to call the parse function
    Factory_master* factory =  new FactoryExpressionTree();
    // call the parse function 
	Base* mult = factory->parse(test, 3);  

    ASSERT_NE(mult, nullptr);
    EXPECT_EQ(mult->stringify(), "2.500000 * 10.000000");
    EXPECT_EQ(mult->evaluate(), 25);
}

TEST(FactoryExpressionTree, subtraction) {
    char* test[3];              // initialize a char pointer array
    test[0] = (char*) "2.5";    // left operand = 2.5
    test[1] = (char*) "-";      // subtraction operation
    test[2] = (char*) "10";     // right operand = 10

    Factory_master* factory =  new FactoryExpressionTree();
    Base* sub = factory->parse(test, 3);   
        
    ASSERT_NE(sub, nullptr);
    EXPECT_EQ(sub->stringify(), "2.500000 - 10.000000");
    EXPECT_EQ(sub->evaluate(), -7.5);
}

TEST(FactoryExpressionTree, division) {
    char* test[3];       
    test[0] = (char*) "2.5" ;       
    test[1] = (char*) "/"   ;       // division operation
    test[2] = (char*) "10"  ;   

    Factory_master* factory =  new FactoryExpressionTree();
    Base* div = factory->parse(test, 3);   

    ASSERT_NE(div, nullptr);
    EXPECT_EQ(div->stringify(), "2.500000 / 10.000000");
    EXPECT_EQ(div->evaluate(), 0.25);
}

TEST(FactoryExpressionTree, power) {
    char* test[3]; 
    test[0] = (char*) "2.5";       
    test[1] = (char*) "**";      // power operation
    test[2] = (char*) "2";       
    
    Factory_master* factory =  new FactoryExpressionTree();
    Base* pow = factory->parse(test, 3);  
    
    ASSERT_NE(pow, nullptr);
    EXPECT_EQ(pow->stringify(), "(2.500000) ** (2.000000)");
    EXPECT_EQ(pow->evaluate(), 6.25);
}

TEST(FactoryExpressionTree, WrongOperationTest) {
    char* test[3];       
    test[0] = (char*) "2.5";       
    test[1] = (char*) "=";       // equal operator 
    test[2] = (char*) "10";     

    Factory_master* factory =  new FactoryExpressionTree();
    
    ASSERT_EQ(factory->parse(test,3), nullptr);    
}

TEST(FactoryExpressionTree, WrongOperand) {
    char* test[3];      
    test[0] = (char*) "2..5";  // left operand = 2..5  (wrong operand)
    test[1] = (char*) "+";      
    test[2] = (char*) "10";      
        
    Factory_master* factory =  new FactoryExpressionTree();
   
    ASSERT_EQ(factory->parse(test,3), nullptr);
}

TEST(FactoryExpressionTree, WrongNumberOfInput) {
    char* test[4];       
    test[0] = (char*) "2.5"; 
    test[1] = (char*) "+";       
    test[2] = (char*) "10";     
	test[4] = (char*) "-";       // extra operator 

    Factory_master* factory =  new FactoryExpressionTree();
    
    ASSERT_EQ(factory->parse(test, 4), nullptr);
}

TEST(FactoryExpressionTree, CombinationTest) {
    char* test[11] ;           // initialize a char pointer array
    test[0] = (char*) "2.5";   // left operand = 2.5
    test[1] = (char*) "/"  ;   // calculate left operand / right operand
    test[2] = (char*) "10" ;   // right operand = 10
    test[3] = (char*) "*"  ;   // calculate left operand * right operand
    test[4] = (char*) "4"  ;   // right operand = 4
	test[5] = (char*) "**" ;   // calculate left operand ** right operand
    test[6] = (char*) "20" ;   // right operand = 20
    test[7] = (char*) "+"  ;   // calculate left operand + right operand
    test[8] = (char*) "9"  ;   // right operand = 9
	test[9] = (char*) "-"  ;   // calculate left operand - right operand
    test[10] = (char*) "10";   // right operand = 10

	Factory_master* factory =  new FactoryExpressionTree();
    Base* expression = factory->parse(test, 11);   
    
    ASSERT_NE(expression, nullptr);
    EXPECT_EQ(expression->stringify(), "(2.500000 / 10.000000 * 4.000000) ** (20.000000) + 9.000000 - 10.000000");
    EXPECT_EQ(expression->evaluate(), 0);
}

#endif //  __FACTORY_EXPRESSION_TREE_UNIT_TEST_HPP__

