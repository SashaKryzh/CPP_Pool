#include "NetworkModule.hpp"

NetworkModule::NetworkModule() : _bytesIn(0), _bytesOut(0) {}

NetworkModule::~NetworkModule() {}

NetworkModule::NetworkModule(const NetworkModule &src)
{
    operator=(src);
}

NetworkModule &NetworkModule::operator=(const NetworkModule &src)
{
    if (this != &src)
    {
    }
    return *this;
}

void NetworkModule::update()
{
    FILE *fp = popen("nettop -J bytes_in,bytes_out -l1 -P -x -n", "r");

    if (fp)
    {
        size_t in = 0;
        size_t out = 0;

        char info[1000];
        fgets(info, sizeof(info), fp); // Skip header
        while (fgets(info, sizeof(info), fp))
        {
            std::stringstream ss;
            ss << info;
            std::string trash;
            size_t n1;
            size_t n2;
            ss >> trash >> trash >> n1 >> n2;
            in += n1;
            out += n2;
        }

        _bytesIn = in / 1048576;
        _bytesOut = out / 1048576;

        pclose(fp);
    }
}

std::vector<std::string> NetworkModule::getData()
{
    update();
    v_str v;
    v.push_back(std::to_string(_bytesIn));
    v.push_back(std::to_string(_bytesOut));
    return v;
}