#include "RAMModule.hpp"
#include "NCursesDisplay.hpp"

#define BI_COL 2

NCursesDisplay::NCursesDisplay() {}
NCursesDisplay::~NCursesDisplay() {}

NCursesDisplay::NCursesDisplay(const NCursesDisplay &src)
{
    operator=(src);
}

NCursesDisplay &NCursesDisplay::operator=(const NCursesDisplay &src)
{
    if (this != &src)
    {
    }
    return *this;
}

void NCursesDisplay::init()
{
    initscr();

    // Config
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Windows
    basicInfo = newwin(HEIGHT, MIDDLE_LINE, 1, 0);
    box(basicInfo, '|', '-');

    cpuActivity = newwin(HEIGHT, CPU_ACTIVITY_WIDTH, 1, MIDDLE_LINE);
    box(cpuActivity, '|', '-');

    ramActivity = newwin(HEIGHT, RAM_ACTIVITY_WIDTH, 1, MIDDLE_LINE + CPU_ACTIVITY_WIDTH);
    box(ramActivity, '|', '-');

    catWindow = newwin(CAT_WINDOW_HEIGHT, CAT_WINDOW_WIDTH, 1, MIDDLE_LINE + CPU_ACTIVITY_WIDTH + RAM_ACTIVITY_WIDTH);
    box(catWindow, '|', '-');

    additional = newwin(HEIGHT - CAT_WINDOW_HEIGHT, CAT_WINDOW_WIDTH, CAT_WINDOW_HEIGHT + 1, MIDDLE_LINE + CPU_ACTIVITY_WIDTH + RAM_ACTIVITY_WIDTH);
    box(additional, '|', '-');

    // Color
    start_color();
    init_pair(1, COLOR_GREEN, 0);
    init_pair(2, COLOR_YELLOW, 0);
    init_pair(3, COLOR_RED, 0);

    // Usage
    mvprintw(0, 0, "ESC - exit");
    refresh();
}

void NCursesDisplay::deinit()
{
    delwin(basicInfo);
    delwin(cpuActivity);
    delwin(ramActivity);
    delwin(catWindow);
    delwin(additional);
    endwin();
}

void NCursesDisplay::refreshWindows()
{
    refresh();
    wrefresh(basicInfo);
    wrefresh(cpuActivity);
    wrefresh(ramActivity);
    wrefresh(catWindow);
    wrefresh(additional);
}

void NCursesDisplay::clearLines()
{
    for (int i = 2; i < HEIGHT - 1; i++)
    {
        mvwprintw(basicInfo, i, 15, "                                  ");
    }
}

void NCursesDisplay::drawStats(std::vector<IMonitorModule *> modules)
{
    std::vector<IMonitorModule *>::iterator it = modules.begin();

    clearLines();
    for (; it != modules.end(); ++it)
    {
        if (dynamic_cast<HostnameModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string hostname = "Username:   " + data[0];
            std::string uid = "Hostname:   " + data[1];
            mvwprintw(basicInfo, 1, 2, hostname.c_str());
            mvwprintw(basicInfo, 2, 2, uid.c_str());
        }

        if (dynamic_cast<OSModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string systemVersion = "System:     " + data[0];
            std::string timeSinceBoot = "Since boot: " + data[1];
            mvwprintw(basicInfo, 4, 2, systemVersion.c_str());
            mvwprintw(basicInfo, 5, 2, timeSinceBoot.c_str());
        }

        if (dynamic_cast<DateTimeModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string time = data[0];
            mvprintw(0, WIDTH - time.length() - 1, time.c_str());
        }

        if (dynamic_cast<CPUModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string cpu;
            if (joke)
                cpu = "CPU:        " + std::string("AMD(R) Ryzen(TM) 3970X");
            else
                cpu = "CPU:        " + data[0];
            std::string speed = "Speed:      " + data[1];
            std::string cores = "Cores:      " + data[2];
            mvwprintw(basicInfo, 7, BI_COL, cpu.c_str());
            mvwprintw(basicInfo, 8, BI_COL, speed.c_str());
            mvwprintw(basicInfo, 9, BI_COL, cores.c_str());

            drawCpuUsage(data[3]);
        }

        if (dynamic_cast<RAMModule *>(*it))
        {
            RAMModule *module = dynamic_cast<RAMModule *>(*it);

            std::vector<ramInfo> slots = module->getRamSlotsData();

            mvwprintw(basicInfo, 11, BI_COL, "Memory");
            size_t i = 0;
            for (; i < slots.size(); ++i)
            {
                std::stringstream ss;
                ss << "Slot " << i + 1 << ": ";

                if (slots[i].size == "Empty")
                {
                    ss << "Empty";
                }
                else
                {
                    ss << slots[i].size << " "
                       << slots[i].type << " "
                       << slots[i].speed;
                }

                mvwprintw(basicInfo, 12 + i, BI_COL, ss.str().c_str());
            }

            RAM_DATA stats = module->getRamData();
            std::stringstream ss1;
            ss1 << "Used:       " << stats.used << " MB";
            std::stringstream ss2;
            ss2 << "Unused:     " << stats.unused << " MB";
            mvwprintw(basicInfo, 12 + i + 1, BI_COL, ss1.str().c_str());
            mvwprintw(basicInfo, 12 + i + 2, BI_COL, ss2.str().c_str());

            drawRamUsage(stats);
        }

        if (dynamic_cast<NetworkModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string in = "In:         " + data[0] + " MB";
            std::string out = "Out:        " + data[1] + " MB";
            mvwprintw(basicInfo, 20, BI_COL, "Network");
            mvwprintw(basicInfo, 21, BI_COL, in.c_str());
            mvwprintw(basicInfo, 22, BI_COL, out.c_str());
        }

        if (dynamic_cast<AdditionalModule*>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string gpu = "GPU: " + data[0];
            std::string serialNumber = "Serial num: " + data[1];
            std::string resolution = "Resolution: " + data[2];

            mvwprintw(additional, 1, BI_COL, gpu.c_str());
            mvwprintw(additional, 3, BI_COL, serialNumber.c_str());
            mvwprintw(additional, 5, BI_COL, resolution.c_str());
            
            mvwprintw(additional, 8, BI_COL, "Fact 1:");
            mvwprintw(additional, 9, BI_COL, "Today is not you birthday");

            mvwprintw(additional, 11, BI_COL, "Fact 2:");
            mvwprintw(additional, 12, BI_COL, "You are not an alien");
        }
    }

    drawCat();
    refreshWindows();
}

void NCursesDisplay::drawCpuUsage(std::string usageString)
{
    try
    {
        int usage = std::stoi(usageString);
        int blocks = usage / 5;

        for (int i = 0; i < 20; ++i)
        {
            if (i > blocks)
                mvwprintw(cpuActivity, CPU_ACTIVITY_HEIGHT - i - 5, 1, "         ");
            else
            {
                int colorPair;
                if (i < 6)
                    colorPair = 1;
                else if (i < 14)
                    colorPair = 2;
                else
                    colorPair = 3;

                wattron(cpuActivity, COLOR_PAIR(colorPair));
                mvwprintw(cpuActivity, CPU_ACTIVITY_HEIGHT - i - 5, 1, "*********");
                wattroff(cpuActivity, COLOR_PAIR(colorPair));
            }
        }
    }
    catch (const std::exception &e)
    {
    }

    std::string s = "CPU";
    s += " %";
    mvwprintw(cpuActivity, 22, 2, s.c_str());
    usageString += "%";
    mvwprintw(cpuActivity, 23, 2, "        ");
    mvwprintw(cpuActivity, 23, 2, usageString.c_str());
}

void NCursesDisplay::drawRamUsage(RAMModule::memoryUsage ramUsage)
{
    int capicity = ramUsage.unused + ramUsage.used;
    int blockUnused = static_cast<int>((static_cast<float>(ramUsage.unused) / static_cast<float>(capicity)) * 20);

    for (int i = 0; i < 20; ++i)
    {
        int colorPair;
        if (i < blockUnused)
            colorPair = 1;
        else
            colorPair = 3;
        wattron(ramActivity, COLOR_PAIR(colorPair));
        mvwprintw(ramActivity, 1 + i, 1, "+++++++++");
        wattroff(ramActivity, COLOR_PAIR(colorPair));
    }

    mvwprintw(ramActivity, 22, 2, "RAM");
    mvwprintw(ramActivity, 23, 2, "Usage");
}

void NCursesDisplay::drawCat()
{
    static int calls;

    std::string cat1[6] = {" |\\__/,|   (`\\",
                           " |_ _  |.--.) )",
                           " ( T   )     /",
                           "(((^_(((/(((_/",
                           "              ",
                           "              "};

    std::string cat2[6] = {" |\\__/,|     )`)",
                           " |o o  |.--.( /",
                           " ( T   )     /",
                           "(((^_(((/(((_/",
                           "              ",
                           "    125/100   "};


    for (int i = 0; i < 6; i++)
    {
        mvwprintw(catWindow, 2 + i, 4, "                   ");
        if (calls / 1)
            mvwprintw(catWindow, 2 + i, 7, cat1[i].c_str());
        else
            mvwprintw(catWindow, 2 + i, 7, cat2[i].c_str());
    }

    calls = (calls + 1) % 3;
}