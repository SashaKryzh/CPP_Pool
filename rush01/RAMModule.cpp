#include "RAMModule.hpp"

RAMModule::RAMModule() {}

RAMModule::~RAMModule() {}

RAMModule::RAMModule(const RAMModule &src)
{
    operator=(src);
}

RAMModule &RAMModule::operator=(const RAMModule &src)
{
    if (this != &src)
    {
    }
    return *this;
}

RAMModule::slotInfo parseRAM(FILE *fp)
{
    ramInfo slot;

    char info[1000];
    std::string str;

    fgets(info, sizeof(info), fp);

    fgets(info, sizeof(info), fp);
    str = info;
    slot.size = deleteNewLine(str.substr(str.find(":") + 2, str.length()));

    fgets(info, sizeof(info), fp);
    str = info;
    slot.type = deleteNewLine(str.substr(str.find(":") + 2, str.length()));

    fgets(info, sizeof(info), fp);
    str = info;
    slot.speed = deleteNewLine(str.substr(str.find(":") + 2, str.length()));

    return slot;
}

void RAMModule::update()
{
}

void RAMModule::updateSlotsData()
{
    FILE *fp = popen("system_profiler SPMemoryDataType", "r");

    if (fp)
    {
        char info[1000];
        while (fgets(info, sizeof(info), fp))
        {
            std::string str(info);

            if (str.find("BANK") != std::string::npos)
            {
                ramInfo slot = parseRAM(fp);
                _slots.push_back(slot);
            }
        }

        pclose(fp);
    }
}

void RAMModule::updateRamData()
{
    FILE *fp = popen("top -l 1 | head -n 10 | grep PhysMem | sed 's/, /n /g'", "r");

    if (fp)
    {
        char info[1000];

        if (fgets(info, sizeof(info), fp))
        {
            std::stringstream ss(info);
            std::string trash;
            ss >> trash >> _usage.used >> trash >> trash >> trash >> trash >> _usage.unused;
        }

        pclose(fp);
    }
}

std::vector<std::string> RAMModule::getData()
{
    v_str ret;
    return ret;
}

std::vector<ramInfo> RAMModule::getRamSlotsData()
{
    if (_slots.empty())
        updateSlotsData();
    return _slots;
}

RAM_DATA RAMModule::getRamData()
{
    updateRamData();
    return _usage;
}