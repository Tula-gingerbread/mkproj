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
#include "mkproj.hpp"

std::string name, temp;
bool welcome_script = false;


std::string lowercase(std::string str)
{    
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return str;
}

void help(void)
{
    std::cout << "License: GNU GPL 3.\n";
    std::cout << "If no --lang and --name arg, run interactively.\n"            ;
    std::cout << "-h --help                 get help and do nothing\n"          ;
    std::cout << "-w --no-welcome-script    don't make `Hello, World!` script\n";
    std::cout << "-l <LANG> --lang <LANG>   specify lang tempelate\n"           ;
    std::cout << "-n <NAME> --name <NAME>   specify project name"   << std::endl;
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

    if (temp.empty() or name.empty()) // Interactive run
    {
        std::cout << "Project tempelate name: ";
        std::getline(std::cin, temp); temp = lowercase(temp);
        if (welcome_script)
        {
            std::string temp_var;
            std::cout << "Make welcome script (Hello, World!)? [Y/n] " << std::endl; std::getline(std::cin, temp_var);
            temp_var = lowercase(temp_var);

            if (temp_var == "n" or temp_var == "no") {welcome_script = false;}
        }
    }


    if (temp == "python") {
        return python(name, welcome_script);
    } else if (temp == "cpp") {

    } else if (temp == "c") {

    } else if (temp == "site") {
        
    } else {
        std::cout << "Unknown tempelate: " << temp << " ." << std::endl;
        return 2;
    }

    return 0;
}
