/*
Licensed under GPL 3.0 -- full license text in file LICENSE
I don't care about Windows!
Program mainly for Linux/GNU, and probably will work on any UNIX-like system 
*/

#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sys/types.h>
#include <sys/stat.h>
#include "include/mkproj.hpp"
#include "include/prepare.hpp"

std::string name, temp;
bool welcome_script = true;


std::string lowercase(std::string str)
{    
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return str;
}

void help(void)
{
    const char * help = R"(License: GNU GPL 3.
    If no --lang and --name arg, run interactively.
    -h --help                 get this help and do nothing
    -w --no-welcome-script    don't make `Hello, World!` script
    -l <LANG> --lang <LANG>   specify lang template. template: cpp (C++), c, python (no case sensitivity)
    -n <NAME> --name <NAME>   specify project name
    )";

    std::cout << help;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 or strcmp(argv[i], "--help") == 0) {
            help();
            return 0;

        } else if (strcmp(argv[i], "-w") == 0 or strcmp(argv[i], "--no-welcome-script") == 0) {
            welcome_script = false;
        } else if (strcmp(argv[i], "-l") == 0 or strcmp(argv[i], "--lang") == 0) {
            try
            {
                temp = argv[i + 1];
            }
            catch (...)
            {
                std::cout << "Error: failed read arg num " << i + 1 << " . Exiting." << std::endl;
                return 2;
            }
        } else if (strcmp(argv[i], "-n") == 0 or strcmp(argv[i], "--name") == 0) {
            try
            {
                name = argv[i + 1];
            }
            catch (...)
            {
                std::cout << "Error: failed read arg num " << i + 1 << " . Exiting." << std::endl;
            }
        }
    }

        if (name.empty())
        {
            std::cout << "Project name: ";
            std::getline(std::cin, name); name = lowercase(name);
        }

        if (temp.empty())
        {
            std::cout << "Project template name: ";
            std::getline(std::cin, temp); temp = lowercase(temp);
        }
        

    if (!prepare(name)) {return 2;}
    if (temp == "python") {
        return python(name, welcome_script);
    } else if (temp == "cpp") {
        return cpp(name, welcome_script);
    } else if (temp == "c") {
        return c(name, welcome_script);
    } else {
        std::cerr << "Unknown template: " << temp << " ." << std::endl;
        return 2;
    }

    return 0;
}
