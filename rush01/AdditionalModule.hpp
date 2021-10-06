#if !defined(ADDITIONAL_MODULE_HPP)
#define ADDITIONAL_MODULE_HPP

#include <unistd.h>

#include "IMonitorModule.hpp"

#include "header.hpp"

class AdditionalModule: public IMonitorModule
{
private:
    std::string _gpu;
    std::string _serialNumber;
    std::string _screenResolution;

public:
    AdditionalModule();
    ~AdditionalModule();

    AdditionalModule(const AdditionalModule &);
    AdditionalModule &operator=(const AdditionalModule &);

    void update();
    std::vector<std::string> getData();
};

#endif // ADDITIONAL_MODULE_HPP
