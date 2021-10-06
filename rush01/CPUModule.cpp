#include "CPUModule.hpp"

CPUModule::CPUModule() : _model(""), _clockSpeed(""), _nbrCores(""), _activity("") {}

CPUModule::~CPUModule() {}

CPUModule::CPUModule(const CPUModule &src)
{
    operator=(src);
}

CPUModule &CPUModule::operator=(const CPUModule &src)
{
    if (this != &src)
    {
    }
    return *this;
}

void CPUModule::update()
{
    FILE *fp = popen("sysctl -n machdep.cpu.brand_string", "r");

    if (fp)
    {
        char info[1000];
        while (fgets(info, sizeof(info), fp))
        {
            std::string str = info;

            size_t pos;
            pos = str.find("@");
            if (pos != std::string::npos)
            {
                _model = str.substr(0, pos - 5);
                _clockSpeed = deleteNewLine(str.substr(pos + 2));
            }
        }

        pclose(fp);
    }

    fp = popen("sysctl -n hw.ncpu", "r");

    if (fp)
    {
        char info[1000];
        while (fgets(info, sizeof(info), fp))
        {
            _nbrCores = deleteNewLine(info);
        }

        pclose(fp);
    }

    fp = popen("top -l 1 | head -n 10 | grep CPU | sed 's/, /n /g'", "r");

    if (fp)
    {
        char info[1000];
        while (fgets(info, sizeof(info), fp))
        {
            std::stringstream ss(info);
            std::string trash;
            float n1;
            float n2;

            ss >> trash >> trash >> n1 >> trash >> trash >> n2;
            n1 += n2;

            std::stringstream ss1;
            ss1 << n1;
            _activity = ss1.str();
        }

        pclose(fp);
    }
}

std::vector<std::string> CPUModule::getData()
{
    update();
    
    v_str v;
    v.push_back(_model);
    v.push_back(_clockSpeed);
    v.push_back(_nbrCores);
    v.push_back(_activity);
    
    return v;
}