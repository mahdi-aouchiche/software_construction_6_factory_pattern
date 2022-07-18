#ifndef __ABS_TEST_HPP__
#define __ABS_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "abs.hpp"

TEST(AbsTest, neg_abs__test) {
    Op* _eight = new Op(-8);
    Abs* test = new Abs(_eight);
    
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(AbsTest, pos_abs__test) {
    Op* eight = new Op(8);
    Abs* test = new Abs(eight);
    
    EXPECT_EQ(test ->evaluate(), 8);
}

TEST(AbsTest, abs_tree_test) {
	Op* _eight = new Op(-8);
	Op* four = new Op(4);
	Op* _eighteen = new Op(-18);
	Op* pi = new Op(3.14);
	Add* branch1 = new Add(_eight, four);
    Add* branch2 = new Add(pi, _eighteen);
    Abs* branch1_abs_value = new Abs(branch1);
	Mult* tree = new Mult( branch1_abs_value, branch2);
    Abs* tree_abs_value = new Abs(tree);
    
    // | (|-8 + 4|) * (3.14 + -18) | = 59.44
    EXPECT_EQ(tree_abs_value->stringify(), "-8.000000 + 4.000000 * 3.140000 + -18.000000");
	EXPECT_EQ(tree_abs_value->evaluate(), 59.44);
}

#endif //__ABS_TEST_HPP__

