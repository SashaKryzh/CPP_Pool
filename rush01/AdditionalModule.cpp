#include "AdditionalModule.hpp"

AdditionalModule::AdditionalModule() : _gpu(""), _serialNumber(""), _screenResolution("") {}

AdditionalModule::~AdditionalModule() {}

AdditionalModule::AdditionalModule(const AdditionalModule &src)
{
    operator=(src);
}

AdditionalModule &AdditionalModule::operator=(const AdditionalModule &src)
{
    if (this != &src)
    {
    }
    return *this;
}

void AdditionalModule::update()
{
    FILE *fp = popen("system_profiler SPDisplaysDataType | sed -n 3p", "r");

    if (fp)
    {
        char info[1000];
        if (fgets(info, sizeof(info), fp))
        {
            std::string str(info);
            size_t start = 0;
            while (isspace(str[start]))
                start++;
            _gpu = deleteNewLine(deleteNewLine(str.substr(start)));
        }

        pclose(fp);
    }

    fp = popen("ioreg -l | grep IOPlatformSerialNumber | cut -d'\"' -f4", "r");

    if (fp)
    {
        char info[1000];
        if (fgets(info, sizeof(info), fp))
        {
            std::string str(info);
            _serialNumber = deleteNewLine(str);
        }

        pclose(fp);
    }

    fp = popen("system_profiler SPDisplaysDataType | awk '/Resolution/{print $2, $3, $4}'", "r");

    if (fp)
    {
        char info[1000];
        if (fgets(info, sizeof(info), fp))
        {
            std::string str(info);
            _screenResolution = deleteNewLine(str);
        }

        pclose(fp);
    }
}

std::vector<std::string> AdditionalModule::getData()
{
    if (_gpu.empty() || _serialNumber.empty() || _screenResolution.empty())
        update();
    v_str v;
    v.push_back(_gpu);
    v.push_back(_serialNumber);
    v.push_back(_screenResolution);
    return v;
}