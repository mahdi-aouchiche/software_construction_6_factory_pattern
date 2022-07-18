#ifndef __FLOOR_TEST_HPP__
#define __FLOOR_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "floor.hpp"

TEST(FloorTest, positive_values) {
        Op* eight = new Op(8);
        Op* four = new Op(4);
        Op* eighteen = new Op(18);
        Op* pi = new Op(3.14);
        Add* eig_four = new Add(eight, four);
        Add* pi_teen = new Add(pi, eighteen);
        Mult* Mult_adds = new Mult( eig_four, pi_teen);
	Floor* floor_test = new Floor(Mult_adds);

        // (8 + 4) * (3.14 + 18) = 12 * 21.14 = 253.68, floor(253.68) = 253
        EXPECT_EQ(floor_test->stringify(), "8.000000 + 4.000000 * 3.140000 + 18.000000");
        EXPECT_EQ(floor_test->evaluate(), 253);    
}

TEST(FloorTest, negative_values) {
	Op* eight = new Op(8);
	Op* four = new Op(4);
	Op* _eighteen = new Op(-18);
	Op* pi = new Op(3.14);
	Add* branch1 = new Add(eight, four);
	Add* branch2 = new Add(pi, _eighteen);
        Mult* mult = new Mult( branch1, branch2);
        Floor* tree = new Floor(mult);
	
        // (8 + 4) * (3.14 + -18) = -178.32, floor(-178.32) = -179. 
        EXPECT_EQ(tree->stringify(), "8.000000 + 4.000000 * 3.140000 + -18.000000");
	EXPECT_EQ(tree->evaluate(), -179);
}

#endif //__FLOOR_TEST_HPP__

