#ifndef __CEIL_TEST_HPP__
#define __CEIL_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "ceil.hpp"

TEST(CeilTest, positive_values) {
    Op* ten         = new Op(10);
    Op* four        = new Op(4);
    Op* eighteen    = new Op(18);
    Op* pi          = new Op(3.14);
    Add* branch1    = new Add(ten, four);
    Add* branch2    = new Add(pi, eighteen);
    Mult* tree      = new Mult( branch1 , branch2);

    // (10+4) * (3.14+18) = 14 * 21.14 = 295.96
    Ceil* ceil_test = new Ceil(tree);
    EXPECT_EQ(ceil_test->evaluate(), 296 );
    EXPECT_EQ(ceil_test->stringify(), "10.000000 + 4.000000 * 3.140000 + 18.000000");
}

TEST(CeilTest, negative_value) {
    Op* _ten        = new Op(-10);
    Op* four       = new Op(4);
    Op* eighteen    = new Op(18);
    Op* pi          = new Op(3.14);
    Add* branch1    = new Add(_ten, four);
    Add* branch2    = new Add(pi,eighteen);
    Mult* tree      = new Mult( branch1 , branch2);

    // (-10 + 4) * (3.14 + 18) = -6 * 21.14 = -126.84  
    Ceil* ceil_test = new Ceil(tree);
    EXPECT_EQ(ceil_test->evaluate(), -126 );
    EXPECT_EQ(ceil_test->stringify(), "-10.000000 + 4.000000 * 3.140000 + 18.000000" );
}

#endif //__CEIL_TEST_HPP__

