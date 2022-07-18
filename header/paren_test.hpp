#ifndef __PAREN_TEST_HPP__
#define __PAREN_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "paren.hpp"

TEST(ParenTest, single_value) {
    Op* eight = new Op(8);
    Paren* test = new Paren(eight);
    
    EXPECT_EQ(test ->stringify(), "(8.000000)");
}

TEST(ParenTest, full_tree_value) {
    Op* eight = new Op(8);
    Op* _one = new Op(-1);

    Add* branch1 = new Add(eight, _one);
    Mult* branch2 = new Mult(eight, _one);

    Paren* p_branch1 = new Paren(branch1);
    Paren* p_branch2 = new Paren(branch2);

    Add* tree = new Add(p_branch1, p_branch2);

    Paren* p_tree = new Paren(tree);
    
    EXPECT_EQ(p_tree->stringify(), "((8.000000 + -1.000000) + (8.000000 * -1.000000))");
    EXPECT_EQ(p_tree->evaluate(), -1);
}

TEST(ParenTest, apply_to_one_branch) {
	Op* eight = new Op(8);
	Op* four = new Op(4);
	Op* eighteen = new Op(18);
	Op* pi = new Op(3.14);
    
	Add* branch1 = new Add(eight, four);
    Add* branch2 = new Add(pi, eighteen);

    Paren* p_test = new Paren(branch2);
	Mult* Mult_adds = new Mult( branch1, p_test);

    EXPECT_EQ(Mult_adds ->stringify(), "8.000000 + 4.000000 * (3.140000 + 18.000000)" );
}

#endif //__PAREN_TEST_HPP__
