/*
Licensed under GPL 3.0 -- full license text in file LICENSE
I don't care about Windows!
Program mainly for Linux/GNU, and probably will work on any UNIX-like system 
*/

#include <cstring>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include "include/mkproj.hpp"
#include "include/prepare.hpp"
#include "include/string_utils.hpp"

std::string name, temp;
bool welcome_script = true;


void help(void)
{
const char * help = R"(License: GNU GPL 3.
If no --lang and --name arg, run interactively.
-h --help                 get this help and do nothing
-w --no-welcome-script    don't make `Hello, World!` script
-l <LANG> --lang <LANG>   specify lang template. templates: python (py); c; c++ (cpp). (no case sensitivity)
-n <NAME> --name <NAME>   specify project name)";

    std::cout << help << std::endl;
}

int main(int argc, char *argv[])
{
    // Parse args
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 or strcmp(argv[i], "--help") == 0) {
            help();
            return 0;

        } else if (strcmp(argv[i], "-w") == 0 or strcmp(argv[i], "--no-welcome-script") == 0) {
            welcome_script = false;
        } else if (strcmp(argv[i], "-l") == 0 or strcmp(argv[i], "--lang") == 0) {
            try {
                temp = trim(lowercase(argv[i + 1]));
            } catch (std::out_of_range) {
                std::cerr << error << "failed read arg num " << i + 1 << std::endl;
                return 2;
            }
        } else if (strcmp(argv[i], "-n") == 0 or strcmp(argv[i], "--name") == 0) {
            try {
                name = trim(argv[i + 1]);
            } catch (std::out_of_range) {
                std::cerr << error << "failed read arg num " << i + 1  << std::endl;
                return 2;
            }
        }
    }
        // Interactive run
        while (name.empty())
        {
            std::cout << "Project name: ";
            std::getline(std::cin, name); name = trim(name);
        }
        
        while (temp.empty())
        {
            std::cout << "Project template name: ";
            std::getline(std::cin, temp); temp = trim(lowercase(temp));
        }
        
    // If error in prepare (file prepare.hpp), exit with code 2
    if (!prepare(name)) {return 2;}
    // Run template creation
    if (temp == "python" or temp == "py") {
        return python(name, welcome_script);
    } else if (temp == "cpp" or temp == "c++") {
        return cpp(name, welcome_script);
    } else if (temp == "c") {
        return c(name, welcome_script);
    } else {
        std::cerr << "Unknown template: " << temp << " ." << std::endl;
        return 2;
    }

    return 0;
}
