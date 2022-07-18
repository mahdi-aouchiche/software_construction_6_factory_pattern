#ifndef __HEADERS_HPP__
#define __HEADERS_HPP__

#include <iostream>
using namespace std;

/* Composite pattern classes */
#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

/* Strategy pattern classes */
#include "container.hpp"
#include "sort.hpp"
#include "list_container.hpp"
#include "vector_container.hpp"
#include "bubble_sort.hpp"
#include "selection_sort.hpp"

/* Decorator pattern classes */
#include "ceil.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"

/* Factory pattern classes */
#include "factory_master.hpp"
#include "factory_expression_tree.hpp"

#endif  //__HEADERS_HPP__