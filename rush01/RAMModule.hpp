#if !defined(RAM_MODULE_HPP)
#define RAM_MODULE_HPP

#include <unistd.h>

#include "IMonitorModule.hpp"

#include "header.hpp"

#define ramInfo RAMModule::slotInfo
#define RAM_DATA RAMModule::memoryUsage

class RAMModule : public IMonitorModule
{
public:
    struct slotInfo
    {
        std::string size;
        std::string type;
        std::string speed;
    };

    struct memoryUsage
    {
        int used;
        int unused;
    };

private:
    std::vector<slotInfo> _slots;
    memoryUsage _usage;

    void updateSlotsData();
    void updateRamData();

public:
    RAMModule();
    ~RAMModule();

    RAMModule(const RAMModule &);
    RAMModule &operator=(const RAMModule &);

    void update();
    std::vector<std::string> getData();
    std::vector<slotInfo> getRamSlotsData();
    memoryUsage getRamData();
};

#endif // RAM_MODULE_HPP
