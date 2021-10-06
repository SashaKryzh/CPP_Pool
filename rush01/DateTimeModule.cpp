#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule() : _dateTime("") {}

DateTimeModule::~DateTimeModule() {}

DateTimeModule::DateTimeModule(const DateTimeModule &src)
{
    operator=(src);
}

DateTimeModule &DateTimeModule::operator=(const DateTimeModule &src)
{
    if (this != &src)
    {
    }
    return *this;
}

void DateTimeModule::update()
{
    FILE *fp = popen("date '+%d.%m.%Y %H:%M:%S'", "r");

    if (fp)
    {
        char info[1000];
        while (fgets(info, sizeof(info), fp))
        {
            _dateTime = deleteNewLine(info);
        }

        pclose(fp);
    }
}

std::vector<std::string> DateTimeModule::getData()
{
    update();
    v_str v;
    v.push_back(_dateTime);
    return v;
}