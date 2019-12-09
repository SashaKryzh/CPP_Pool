#if !defined(CENTRAL_BUREAUCRACY_HPP)
#define CENTRAL_BUREAUCRACY_HPP

#include <string>

#include "OfficeBlock.hpp"

class CentralBureaucracy
{
private:
    struct s_queueTargets
    {
        std::string name;
        s_queueTargets *next;
    };

    OfficeBlock blocks_[20];
    s_queueTargets *queueTargets_;

    std::string *dequeueTarget();
    
public:
    CentralBureaucracy();
    ~CentralBureaucracy();

    CentralBureaucracy(const CentralBureaucracy &);
    CentralBureaucracy &operator=(const CentralBureaucracy &);

    void feedBureaucrat(Bureaucrat &);
    void queueUp(std::string target);
    void doBureaucracy();
};

#endif // CENTRAL_BUREAUCRACY_HPP
