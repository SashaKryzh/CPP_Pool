#include "header.hpp"

std::string deleteNewLine(std::string str)
{
    return str.substr(0, str.length() - 1);
}