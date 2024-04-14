// Licensed under GPL 3.0 -- full license text in file LICENSE
#include "hello_world.hpp"

std::string cpp_hello_world = R"(#include <iostream>

int main(void)
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
)";

std::string c_hello_world = R"(#include <stdio.h>

int main(void)
{
    printf("Hello, World!");
    return 0;
}
)";

std::string python_hello_world = "print('Hello, World!')\n";
