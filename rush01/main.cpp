#include <iostream>

#include "header.hpp"

#include "NCursesDisplay.hpp"
#include "MLXDisplay.hpp"

int joke = 1;

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        std::string arg = av[1];
        if (arg == "-joke")
            joke = 0;
    }

    HostnameModule hostnameModule;
    OSModule osModule;
    DateTimeModule timeModule;
    CPUModule cpuModule;
    RAMModule ramModule;
    NetworkModule networkModule;
    AdditionalModule additionalModule;
    
    NCursesDisplay ncurses;
    MLXDisplay mlx;
    ncurses.init();
    std::vector<IMonitorModule*> v;
    v.push_back(&hostnameModule);
    v.push_back(&osModule);
    v.push_back(&timeModule);
    v.push_back(&cpuModule);
    v.push_back(&ramModule);
    v.push_back(&networkModule);
    v.push_back(&additionalModule);
    mlx.init();
    while(true)
    {
        int key = getch();
        if (key == 27)
            break;

        ncurses.drawStats(v);
        mlx.drawStats(v);
        usleep(100000);
    }

    ncurses.deinit();
    return 0;
}