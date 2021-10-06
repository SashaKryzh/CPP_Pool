#if !defined(HOSTNAME_MODULE_HPP)
#define HOSTNAME_MODULE_HPP

#include <unistd.h>

#include "IMonitorModule.hpp"

#include "header.hpp"

class HostnameModule: public IMonitorModule
{
private:
    std::string _uid;
    std::string _hostname;

public:
    HostnameModule();
    ~HostnameModule();

    HostnameModule(const HostnameModule &);
    HostnameModule &operator=(const HostnameModule &);

    void update();
    std::vector<std::string> getData();
};

#endif // HOSTNAME_MODULE_HPP
