// Licensed under GPL 3.0 -- full license text in file LICENSE
#include "mkproj.hpp"
#include "gitignores.hpp"
#include "hello_world.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <fstream>

int python(std::string name, bool welcome_script)
{
    std::string version;

    std::cout << "Python version (major.minor without patch or type nothing for global python): ";
    std::getline(std::cin, version);

    std::cout << ":: Making venv (.env).\n\
    :: Hint -- to activate venv run \n\
    -> `source .env/bin/activate` for bash; or `source .env/bin/activate.[fish or csh] for fish or csh`" << std::endl;
    system(("/usr/bin/env python" + version + " -m venv .env").c_str()); // python env


    std::ofstream requirements("requirements.txt"); requirements.close();

    if (welcome_script) {
        std::cout << ":: Writing welcome script..." << std::endl;
        std::ofstream main_py("main.py");
            if (!main_py) {
            std::cerr << "Failed to open file \"main.py\".\nNot critical -- continue" << std::endl;
        } else {
            main_py << python_hello_world;
            main_py.close();
        }
    }
    
    std::cout << ":: Writing .gitignore..." << std::endl;
    std::ofstream gitignore(".gitignore");
    if (gitignore) {
        gitignore << python_gitignore_template;
        gitignore.close();
    } else {
        std::cerr << "Failed to open file \".gitignore\"!" << std::endl; return 1;
    }
    std::cout << "MkProj for Python " << version << " success." << std::endl;
    return 0;
}

int cpp(std::string name, bool welcome_script)
{
    
    if (welcome_script) {
        std::cout << ":: Writing welcome script..." << std::endl;
        std::ofstream main_cpp("main.cpp");
        if (main_cpp) {main_cpp << cpp_hello_world;} else {
            std::cerr << "Failed to open file \"main.cpp\".\nNot critical -- continue" << std::endl;
        }
    }

    std::cout << ":: Writing .gitignore..." << std::endl;
    std::ofstream gitignore(".gitignore");
    if (gitignore) {gitignore << cpp_gitignore_template;} else {
        std::cerr << "Failed to open file \".gitignore\"!" << std::endl;
        return 1;
    }

    std::cout << "MkProj for C++ success." << std::endl;
    return 0;
}

int c(std::string name, bool welcome_script)
{
    if (welcome_script) {
        std::cout << ":: Writing welcome script..." << std::endl;
        std::ofstream main_c("main.c");
        if (main_c) {main_c << c_hello_world;} else {
            std::cerr << "Failed to open file \"main.c\".\nNot critical -- continue" << std::endl;
        }
    }

    std::cout << ":: Writing .gitignore..." << std::endl;
    std::ofstream gitignore(".gitignore");
    if (gitignore) {gitignore << c_gitignore_template;} else {
        std::cerr << "Failed to open file \".gitignore\"!" << std::endl;
        return 1;
    }

    std::cout << "MkProj for C success." << std::endl;
    return 0;
}
