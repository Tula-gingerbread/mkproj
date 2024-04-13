// Licensed under GPL 3.0 -- full license text in file LICENSE

#include "mkproj.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <fstream>


bool mkdir_pp(std::string name)
{
    if ( mkdir(name.c_str(), 0750) != 0) {
        std::cout << "Error in creating dir!" << std::endl; return false;
    }
    std::filesystem::current_path(name);
    return true;
}

int python(std::string name, bool welcome_script)
{
    std::string version;

    std::cout << "Python version (major.minor without patch or type nothing for global python): ";
    std::getline(std::cin, version);
    if (!mkdir_pp(name)) {return 2;}
    
    system(("/usr/bin/env python" + version + " -m venv .env").c_str()); // python env

    system("touch main.py requirements.txt README .env/.gitignore"); // basic files

    // Welcome script
    if (welcome_script) {
        std::cout << ":: Writing welcome script..." << std::endl;
        std::ofstream main_py("main.py");
            if (!main_py) {
            std::cerr << "Failed to open file \"main.py\".\nNot critical -- continue" << std::endl;
        } else {
            main_py << "print(\"Hello, World!\")\n";
            main_py.close();
        }
    }

    // README
    std::cout << ":: Writing README..." << std::endl;
    std::ofstream readme("README");
    if (!readme) {
        std::cerr << "Failed to open file \"README\".\nNot critical -- continue." << std::endl;
    } else {
        readme << "# " << name << "\n\n";
        readme.close();
    }

    // gitignore for env
    std::ofstream gitignore(".env/.gitignore");
    if (gitignore) {
        gitignore << "*\n";
        gitignore.close();
    } else {
        std::cerr << "Failed to open file \".env/.gitignore\"!" << std::endl;
        return 1;
    }
    std::cout << "MkProj for Python " << version << " success." << std::endl;

    return 0;
}
