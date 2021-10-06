#if !defined(OS_MODULE_HPP)
#define OS_MODULE_HPP

#include <unistd.h>

#include "IMonitorModule.hpp"
#include "header.hpp"

class OSModule: public IMonitorModule
{
private:
    std::string _systemVersion;
    std::string _timeSinceBoot;

    void updateTimeSinceBoot();

public:
    OSModule();
    ~OSModule();

    OSModule(const OSModule &);
    OSModule &operator=(const OSModule &);

    void update();
    std::vector<std::string> getData();
};

#endif // OS_MODULE_HPP
