// Licensed under GPL 3.0 -- full license text in file LICENSE
#ifndef PREPARE_HPP
#define PREPARE_HPP

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>


inline bool prepare(const std::string name)
{
    // Make dir and cd to it    
    if ( mkdir(name.c_str(), 0750) != 0 ) {
        std::cerr << "Error in creating dir! Maybe, dir exists or you haven't enough perms." << std::endl;
        return false;
    }
    std::filesystem::current_path(name);

    std::cout << ":: Writing README..." << std::endl;
    std::ofstream readme("README");
    if (readme) {
        readme << "# " << name << "\n";
        readme.close();
    } else {
        std::cerr << "Failed to open file \"README\".\nNot critical -- continue." << std::endl;
    }

    return true;
}

#endif