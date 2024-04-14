#ifndef ANSI_ESCAPE_HPP
#define ANSI_ESCAPE_HPP

#include <string>

const std::string bold = "\033[1m";
const std::string red = "\033[31m";
const std::string yellow = "\033[33m";
const std::string green = "\033[32m";
const std::string light_blue = "\033[94m";
const std::string reset = "\033[0m";

const std::string info = light_blue + ":: " + reset;
const std::string error = bold + red + "Error: " + reset;
const std::string warning = bold + yellow + "Warning: " + reset;


#endif