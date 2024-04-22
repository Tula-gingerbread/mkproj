
#include <algorithm>
#include <string>
#include "string_utils.hpp"


// Transform str to lowercase
std::string lowercase(std::string str)
{    
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return str;
}


// Remove whitespace
std::string trim(std::string str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());

    return str;
}