// Licensed under GPL 3.0 -- full license text in file LICENSE

#ifndef MKPROJ_HPP
#define MKPROJ_HPP

#include <string>

int python(std::string name, bool welcome_script);
int cpp(std::string name), c(std::string name);
int site(std::string name);
bool mkdir_pp(std::string name);

#endif