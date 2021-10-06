#if !defined(DATE_TIME_MODULE_HPP)
#define DATE_TIME_MODULE_HPP

#include <unistd.h>

#include "IMonitorModule.hpp"

#include "header.hpp"

class DateTimeModule: public IMonitorModule
{
private:
    std::string _dateTime;

public:
    DateTimeModule();
    ~DateTimeModule();

    DateTimeModule(const DateTimeModule &);
    DateTimeModule &operator=(const DateTimeModule &);

    void update();
    std::vector<std::string> getData();
};

#endif // DATE_TIME_MODULE_HPP
