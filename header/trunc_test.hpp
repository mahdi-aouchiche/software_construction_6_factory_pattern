#ifndef __TRUNC_TEST_HPP__
#define __TRUNC_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "trunc.hpp"

TEST(TruncTest, single_value) {
   Op* one     = new Op(1);
   Trunc* test = new Trunc(one);

   EXPECT_EQ(one->stringify(), "1.000000");
   EXPECT_EQ(test->stringify(), "1.000000");
}

TEST(TruncTest, single_tree) {
   Op* _two  = new Op(-2);
   Op* one   = new Op(1);
   Op* three = new Op(3);
   Add* branch1  = new Add(one, three);
   Mult* branch2 = new Mult(_two, branch1);
   Trunc* test = new Trunc(branch2);

   EXPECT_EQ(branch2->evaluate(), -8);
   EXPECT_EQ(branch2->stringify(), "-2.000000 * 1.000000 + 3.000000");
   EXPECT_EQ(test->evaluate(), -8);
   EXPECT_EQ(test->stringify(), "-8.000000");
}

TEST(TruncTest, large_tree) {
   Op* eight 	  = new Op(8);
   Op* four 	  = new Op(4);
   Op* ten 	  = new Op(10);
   Op* one	  = new Op(1);
   Add* branch1   = new Add(eight, four);
   Add* branch2   = new Add(ten, one);
   Mult* tree     = new Mult( branch1, branch2);
   Trunc* trunc_test = new Trunc(branch2);
   Mult* truncated   = new Mult(branch1, trunc_test);

   EXPECT_EQ(tree->stringify(), "8.000000 + 4.000000 * 10.000000 + 1.000000");
   EXPECT_EQ(trunc_test->stringify(), "11.000000" );
   EXPECT_EQ(truncated->stringify(), "8.000000 + 4.000000 * 11.000000" );
}

#endif //__TRUNC_TEST_HPP__

