#include "OSInfoModule.hpp"

OSModule::OSModule() : _systemVersion(""),  _timeSinceBoot("") {}

OSModule::~OSModule() {}

OSModule::OSModule(const OSModule &src)
{
    operator=(src);
}

OSModule &OSModule::operator=(const OSModule &src)
{
    if (this != &src)
    {
    }
    return *this;
}

#include <iostream>

void OSModule::update()
{
    FILE *fp = popen("system_profiler SPSoftwareDataType", "r");

    static const std::string sV = "System Version: ";
    static const std::string tB = "Time since boot: ";

    _systemVersion = "";
    _timeSinceBoot = "";

    if (fp)
    {
        char info[1000];
        while (fgets(info, sizeof(info), fp))
        {
            std::string str(info);
            
            size_t pos;
            
            if ((pos = str.find(sV)) != std::string::npos)
            {
                _systemVersion = deleteNewLine(str.substr(pos + sV.length()));
            }
            else if ((pos = str.find(tB)) != std::string::npos)
            {
                _timeSinceBoot = deleteNewLine(str.substr(pos + tB.length()));
            }

            if (_systemVersion.empty() == false && _timeSinceBoot.empty() == false)
                break;
        }

        pclose(fp);
    }
}

std::vector<std::string> OSModule::getData()
{
    update();
    v_str v;
    v.push_back(_systemVersion);
    v.push_back(_timeSinceBoot);
    return v;
}