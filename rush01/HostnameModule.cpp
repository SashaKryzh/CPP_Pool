#include "HostnameModule.hpp"

HostnameModule::HostnameModule() : _uid(""), _hostname("") {}

HostnameModule::~HostnameModule() {}

HostnameModule::HostnameModule(const HostnameModule &src)
{
    operator=(src);
}

HostnameModule &HostnameModule::operator=(const HostnameModule &src)
{
    if (this != &src)
    {
    }
    return *this;
}

void HostnameModule::update()
{
    char *uid = getlogin();
    if (uid != NULL)
        _uid = uid;

    char hostname[100];
    gethostname(hostname, 100);
    _hostname = hostname;
}

std::vector<std::string> HostnameModule::getData()
{
    if (_hostname.empty() || _uid.empty())
        update();
    v_str v;
    v.push_back(_uid);
    v.push_back(_hostname);
    return v;
}