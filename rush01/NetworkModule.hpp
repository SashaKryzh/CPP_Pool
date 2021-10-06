#if !defined(NETWORK_MODULE_HPP)
#define NETWORK_MODULE_HPP

#include <unistd.h>

#include "IMonitorModule.hpp"

#include "header.hpp"

class NetworkModule: public IMonitorModule
{
private:
    size_t _bytesIn;
    size_t _bytesOut;

public:
    NetworkModule();
    ~NetworkModule();

    NetworkModule(const NetworkModule &);
    NetworkModule &operator=(const NetworkModule &);

    void update();
    std::vector<std::string> getData();
};

#endif // NETWORK_MODULE_HPP
