#if !defined(HEADER_HPP)
#define HEADER_HPP

#include <iostream>
#include <sstream>

#define v_str std::vector<std::string>

#include "IMonitorModule.hpp"

#include "HostnameModule.hpp"
#include "OSInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"
#include "AdditionalModule.hpp"

// #include "NCursesDisplay.hpp"

extern int joke;

std::string deleteNewLine(std::string str);

#endif // HEADER_HPP
