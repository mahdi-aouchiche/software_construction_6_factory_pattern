# Software Construction: Factory Pattern

> Author: Mahdi Aouchiche (<https://github.com/mahdi-aouchiche/software_construction_6_factory_pattern>)

Create a factory which can take in user input and generate a correct expression tree, represented by a `Base*` root node which will be returned to the caller.
The factory should have a single public method `Base* parse(char** input, int length)`. Parse the inputs to generate the corresponding expression tree, assume there are no parenthesies and spaces between each number and operator. Also no need to consider precedence for the operations and assume they should be executed from left to right.
For example, the input `3 + 2 * 6` would result in `(3 + 2) * 6 = 30` rather than the normal `3 + (2 * 6) = 15` In the case that the input is invalid, print an error and return back a `nullptr` to the caller.

> Note: Only need to be able to parse numbers and the operators defined in the composite pattern lab. No need to parse additional features such as the decorators.

* The main executable should be named `calculator` and should take the `char** argv` and the `int argc` input to main and pass it to the factory. The factory should then convert it to an expression tree, and then print the `stringify()` and `evaluate()` values of the generated expression tree back to the user.

> Note: When you run something like `./calculator 4 * 3` or `./calculator 4 ** 3`, Bash will see the `*` and treat it as a [wildcard operator](https://tldp.org/LDP/GNU-Linux-Tools-Summary/html/x11655.htm).
To avoid this issue, just prepend the `*` character with `\` on the command line. So, you should run `./calculator 4 \* 3` or `./calculator 4 \*\* 3` instead of the commands above.

## To run the project nicely use the following commands

```c++
cmake -S . -B build
cmake --build build/
```

## 6 executables are created, use one of the commands to run an executable

```c++
// composite pattern
./build/composite_tests
./build/composite_pattern
// strategy pattern
./build/strategy_tests
./build/strategy_pattern
// decorator pattern
./build/decorator_tests
./build/decorator_pattern
// factory pattern
./build/factory_tests
./build/calculator <see note above>
```
