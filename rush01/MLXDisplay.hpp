#if !defined(MLX_DISPLAY_HPP)
#define MLX_DISPLAY_HPP

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

class MLXDisplay: public IMonitorDisplay
{
private:
    void	*mlx_ptr;
    void	*win_ptr;
    char	*img1;
    void	*img2;
    int		window_width;
    int		window_height;
    void refreshWindows();

    void clearLines();

    void drawCpuUsage(std::string usage);
    void drawRamUsage(RAMModule::memoryUsage ramUsage);
    void drawCat();

public:
    MLXDisplay();
    ~MLXDisplay();

    MLXDisplay(const MLXDisplay &);
    MLXDisplay &operator=(const MLXDisplay &);

    void init();
    void deinit();

    void drawStats(std::vector<IMonitorModule*> modules);
};

#endif // MLX_DISPLAY_HPP
