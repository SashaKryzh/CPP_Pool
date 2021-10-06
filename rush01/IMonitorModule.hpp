#if !defined(IMONITOR_MODULE_HPP)
#define IMONITOR_MODULE_HPP

#include <string>
#include <vector>

class IMonitorModule
{
public:
    virtual ~IMonitorModule() {}
    virtual void update() = 0;
    virtual std::vector<std::string> getData() = 0;
};

#endif // IMONITOR_MODULE_HPP
