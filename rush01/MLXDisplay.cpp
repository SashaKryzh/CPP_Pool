#include "RAMModule.hpp"
#include "MLXDisplay.hpp"

#define BI_COL 2

MLXDisplay::MLXDisplay() {}
MLXDisplay::~MLXDisplay() {}

MLXDisplay::MLXDisplay(const MLXDisplay &src)
{
    operator=(src);
}

MLXDisplay &MLXDisplay::operator=(const MLXDisplay &src)
{
    if (this != &src)
    {
    }
    return *this;
}

extern "C"	void mlx_initialize(void	**mlx_ptr, void **win_ptr,
void **img2, char **img1, int *window_width, int *window_height);
extern "C"	void mlx_refresh(void *mlx_ptr);
extern "C"	void mlx_string_to_win(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx);
extern "C"  void mlx_string_to_win_red(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx);
extern "C"  void mlx_string_to_win_green(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx);
extern "C"  void mlx_string_to_win_yellow(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx);
void MLXDisplay::init()
{
	mlx_initialize(&this->mlx_ptr, &this->win_ptr,
		&this->img2, &this->img1, &this->window_width, &this->window_height);
	//mlx_refresh(this->mlx_ptr);
}

void MLXDisplay::deinit()
{
    // delwin(basicInfo);
    // delwin(cpuActivity);
    // delwin(ramActivity);
    // delwin(catWindow);
    // delwin(additional);
    // endwin();
}

void MLXDisplay::refreshWindows()
{
	//put_igame
    // refresh();
    // wrefresh(basicInfo);
    // wrefresh(cpuActivity);
    // wrefresh(ramActivity);
    // wrefresh(catWindow);
    // wrefresh(additional);
}

void MLXDisplay::clearLines()
{
    // for (int i = 2; i < HEIGHT - 1; i++)
    // {
    //     mvwprintw(basicInfo, i, 15, "                                  ");
    // }
}

void MLXDisplay::drawStats(std::vector<IMonitorModule *> modules)
{
    std::vector<IMonitorModule *>::iterator it = modules.begin();
//    clearLines();
    for (; it != modules.end(); ++it)
    {
        if (dynamic_cast<HostnameModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string hostname = "Username:   " + data[0];
            std::string uid = "Hostname:   " + data[1];
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 20, 40, hostname.c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 40, 40, uid.c_str());
        }

        if (dynamic_cast<OSModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string systemVersion = "System:     " + data[0];
            std::string timeSinceBoot = "Since boot: " + data[1];
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 80, 40, systemVersion.c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 100, 40, timeSinceBoot.c_str());
        }

        if (dynamic_cast<DateTimeModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string time = data[0];

            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 0, 10, time.c_str());
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
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 7 * 20, 40, cpu.c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 8 * 20, 40, speed.c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 9 * 20, 40, cores.c_str());

            drawCpuUsage(data[3]);
        }

        if (dynamic_cast<RAMModule *>(*it))
        {
            RAMModule *module = dynamic_cast<RAMModule *>(*it);

            std::vector<ramInfo> slots = module->getRamSlotsData();

            mlx_string_to_win(this->mlx_ptr, this->win_ptr, (11) * 20, 40, "Memory");
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
                mlx_string_to_win(this->mlx_ptr, this->win_ptr, (12 + i) * 20, 40, ss.str().c_str());
            }

            RAM_DATA stats = module->getRamData();
            std::stringstream ss1;
            ss1 << "Used:       " << stats.used << " MB";
            std::stringstream ss2;
            ss2 << "Unused:     " << stats.unused << " MB";

            mlx_string_to_win(this->mlx_ptr, this->win_ptr, (12 + i + 1) * 20, 40, ss1.str().c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, (12 + i + 2) * 20, 40, ss2.str().c_str());

            drawRamUsage(stats);
        }

        if (dynamic_cast<NetworkModule *>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string in = "In:         " + data[0] + " MB";
            std::string out = "Out:        " + data[1] + " MB";

            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 400, 40, "Network");
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 420, 40, in.c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 440, 40, out.c_str());
        }

        if (dynamic_cast<AdditionalModule*>(*it))
        {
            std::vector<std::string> data = (*it)->getData();
            std::string gpu = "GPU: " + data[0];
            std::string serialNumber = "Serial num: " + data[1];
            std::string resolution = "Resolution: " + data[2];

            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 220, 550, gpu.c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 260, 550, serialNumber.c_str());
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 300, 550, resolution.c_str());

            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 360, 550, "Fact 1:");
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 380, 550, "Today is not you birthday");

            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 420, 550, "Fact 2:");
            mlx_string_to_win(this->mlx_ptr, this->win_ptr, 440, 550, "You are not an alien");
        }
    }

    drawCat();
    mlx_refresh(&this->mlx_ptr);
}

void MLXDisplay::drawCpuUsage(std::string usageString)
{
    try
    {
        int usage = std::stoi(usageString);
        int blocks = usage / 5;

        for (int i = 0; i < 20; ++i)
        {
            if (i > blocks)
            	mlx_string_to_win(this->mlx_ptr, this->win_ptr, (CPU_ACTIVITY_HEIGHT - i - 5) * 20, 350, "        ");
            else
            {
                if (i < 6)
                	mlx_string_to_win_green(this->mlx_ptr, this->win_ptr, (CPU_ACTIVITY_HEIGHT - i - 5) * 20, 350, "*********");
                else if (i < 14)
                    mlx_string_to_win_yellow(this->mlx_ptr, this->win_ptr, (CPU_ACTIVITY_HEIGHT - i - 5) * 20, 350, "*********");
                else
                    mlx_string_to_win_red(this->mlx_ptr, this->win_ptr, (CPU_ACTIVITY_HEIGHT - i - 5) * 20, 350, "*********");
            }
        }
    }
    catch (const std::exception &e)
    {
    }

    std::string s = "CPU";
    s += " %";
    mlx_string_to_win(this->mlx_ptr, this->win_ptr, 22 * 20, 350, s.c_str());
    usageString += "%";
    mlx_string_to_win(this->mlx_ptr, this->win_ptr, 23 * 20, 350, usageString.c_str());
}

void MLXDisplay::drawRamUsage(RAMModule::memoryUsage ramUsage)
{
    int capicity = ramUsage.unused + ramUsage.used;
    int blockUnused = static_cast<int>((static_cast<float>(ramUsage.unused) / static_cast<float>(capicity)) * 20);

    for (int i = 0; i < 20; ++i)
    {
        if (i < blockUnused)
        	mlx_string_to_win_green(this->mlx_ptr, this->win_ptr, (1 + i) * 20, 450, "+++++++++");
        else
        	mlx_string_to_win_red(this->mlx_ptr, this->win_ptr, (1 + i) * 20, 450, "+++++++++");
    }

	mlx_string_to_win(this->mlx_ptr, this->win_ptr, 22 * 20, 450, "RAM");
	mlx_string_to_win(this->mlx_ptr, this->win_ptr, 23 * 20, 450, "Usage");
}

void MLXDisplay::drawCat()
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
        if (calls / 1)
    		mlx_string_to_win(this->mlx_ptr, this->win_ptr, 20 * i, 550, cat1[i].c_str());
        else
    		mlx_string_to_win(this->mlx_ptr, this->win_ptr, 20 * i, 550, cat2[i].c_str());
    }

    calls = (calls + 1) % 3;
}
