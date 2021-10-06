#if !defined(IMONITOR_DISPLAY_HPP)
#define IMONITOR_DISPLAY_HPP

class IMonitorDisplay
{
public:
    virtual ~IMonitorDisplay() {};
    virtual void init() = 0;
    virtual void deinit() = 0;
};

#endif // IMONITOR_DISPLAY_HPP
