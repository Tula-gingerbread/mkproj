// Licensed under GPL 3.0 -- full license text in file LICENSE
#include "mkproj.hpp"
#include "gitignores.hpp"
#include "string_utils.hpp"
#include "hello_world.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <fstream>


int python(const std::string name, const bool welcome_script)
{
    std::string version;

    std::cout << "Python version (major.minor without patch or type nothing for global python): ";
    std::getline(std::cin, version);

    std::cout << info << "Making venv (.env).\n";
    std::cout << info << "Hint -- to activate venv run \n";
    std::cout << \
    "    -> `source .env/bin/activate` for bash; or `source .env/bin/activate.[fish or csh] for fish or csh`" << std::endl;
    
    const int retcode = system(("/usr/bin/env python" + version + " -m venv .env").c_str()); // python env
    if (retcode != 0) {
        std::cerr << error << "Failed create python venv!" << std::endl;
        return 2;
    }

    std::ofstream requirements("requirements.txt");
    if (requirements) {
        requirements.close();
    } else {
        std::cerr << warning << "failed to open file \"requirements.txt\"" << std::endl;
    }

    if (welcome_script) {
        std::cout << info << "Writing welcome script..." << std::endl;
        std::ofstream main_py("main.py");
            if (!main_py) {
            std::cerr << warning << "failed to open file \"main.py\"" << std::endl;
        } else {
            main_py << python_hello_world;
            main_py.close();
        }
    }

    std::cout << info << "Writing .gitignore..." << std::endl;
    std::ofstream gitignore(".gitignore");
    if (gitignore) {
        gitignore << python_gitignore_template;
        gitignore.close();
    } else {
        std::cerr << error << "Failed to open file \".gitignore\"!" << std::endl; return 1;
    }
    if (!version.empty()) {
        std::cout << green << "MkProj for Python " << version << " success." << reset << std::endl;
    } else {
        std::cout << green <<  "MkProj for Python success." << reset << std::endl;
    }
    return 0;
}

int cpp(const std::string name, const bool welcome_script)
{
    
    if (welcome_script) {
        std::cout << info << "Writing welcome script..." << std::endl;
        std::ofstream main_cpp("main.cpp");
        if (main_cpp) {
            main_cpp << cpp_hello_world;
            main_cpp.close();
        } else {
            std::cerr << error << "Failed to open file \"main.cpp\".\nNot critical -- continue" << std::endl;
        }
    }

    std::cout << info << "Writing .gitignore..." << std::endl;
    std::ofstream gitignore(".gitignore");
    if (gitignore) {
        gitignore << cpp_gitignore_template;
        gitignore.close();
    } else {
        std::cerr << error <<"Failed to open file \".gitignore\"!" << std::endl;
        return 1;
    }

    std::cout << green << "MkProj for C++ success." << reset << std::endl;
    return 0;
}

int c(const std::string name, const bool welcome_script)
{
    if (welcome_script) {
        std::cout << ":: Writing welcome script..." << std::endl;
        std::ofstream main_c("main.c");
        if (main_c) {
        main_c << c_hello_world;
        main_c.close();
        } else {
            std::cerr << error << "Failed to open file \"main.c\"" << std::endl;
        }
    }

    std::cout << info << "Writing .gitignore..." << std::endl;
    std::ofstream gitignore(".gitignore");
    if (gitignore) {
        gitignore << c_gitignore_template;
        gitignore.close();
    } else {
        std::cerr << error << "Failed to open file \".gitignore\"!" << std::endl;
        return 1;
    }

    std::cout << green << "MkProj for C success." << reset << std::endl;
    return 0;
}
