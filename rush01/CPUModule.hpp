#if !defined(CPU_MODULE_HPP)
#define CPU_MODULE_HPP

#include <unistd.h>

#include "IMonitorModule.hpp"

#include "header.hpp"

class CPUModule: public IMonitorModule
{
private:
    std::string _model;
    std::string _clockSpeed;
    std::string _nbrCores;
    std::string _activity;

public:
    CPUModule();
    ~CPUModule();

    CPUModule(const CPUModule &);
    CPUModule &operator=(const CPUModule &);

    void update();
    std::vector<std::string> getData();
};

#endif // CPU_MODULE_HPP
