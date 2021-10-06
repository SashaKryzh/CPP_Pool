#if !defined(NCURSES_DISPLAY_HPP)
#define NCURSES_DISPLAY_HPP

#include <ncurses.h>

#include "header.hpp"

#include "IMonitorDisplay.hpp"

#define HEIGHT 25
#define WIDTH 103

#define MIDDLE_LINE 50

#define CPU_ACTIVITY_HEIGHT 25
#define CPU_ACTIVITY_WIDTH 11

#define RAM_ACTIVITY_HEIGHT 25
#define RAM_ACTIVITY_WIDTH 11

#define CAT_WINDOW_HEIGHT 9
#define CAT_WINDOW_WIDTH 30

class NCursesDisplay: public IMonitorDisplay
{
private:
    WINDOW *basicInfo;
    WINDOW *cpuActivity;
    WINDOW *ramActivity;
    WINDOW *catWindow;
    WINDOW *additional;

    void refreshWindows();

    void clearLines();

    void drawCpuUsage(std::string usage);
    void drawRamUsage(RAMModule::memoryUsage ramUsage);
    void drawCat();

public:
    NCursesDisplay();
    ~NCursesDisplay();

    NCursesDisplay(const NCursesDisplay &);
    NCursesDisplay &operator=(const NCursesDisplay &);

    void init();
    void deinit();

    void drawStats(std::vector<IMonitorModule*> modules);
};

#endif // NCURSES_DISPLAY_HPP
