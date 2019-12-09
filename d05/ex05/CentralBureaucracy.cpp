#include "CentralBureaucracy.hpp"
#include <unistd.h>

CentralBureaucracy::CentralBureaucracy() : queueTargets_(nullptr) {}

CentralBureaucracy::~CentralBureaucracy()
{
    while (dequeueTarget())
    {
    }
}

CentralBureaucracy::CentralBureaucracy(const CentralBureaucracy &src) : queueTargets_(nullptr)
{
    operator=(src);
}

CentralBureaucracy &CentralBureaucracy::operator=(const CentralBureaucracy &src)
{
    if (this != &src)
    {
        // Copy blocks
        for (int i = 0; i < 20; i++)
        {
            if (src.blocks_[i].getSigner() || src.blocks_[i].getExecuter())
            {
                blocks_[i].setIntern(*(new Intern()));
                blocks_[i].setSigner(*(new Bureaucrat(*(src.blocks_[i].getSigner()))));
                blocks_[i].setExecutor(*(new Bureaucrat(*(src.blocks_[i].getExecuter()))));
            }
        }
        // Copy queue
        s_queueTargets *tmp = src.queueTargets_;
        while (tmp != nullptr)
        {
            queueUp(tmp->name);
            tmp = tmp->next;
        }
    }
    return *this;
}

void CentralBureaucracy::feedBureaucrat(Bureaucrat &b)
{
    for (int i = 0; i < 20; i++)
    {
        if (blocks_[i].getSigner() == nullptr || blocks_[i].getExecuter() == nullptr)
        {
            if (blocks_[i].getSigner() == nullptr)
                blocks_[i].setSigner(b);
            else
                blocks_[i].setExecutor(b);
            if (blocks_[i].getIntern() == nullptr)
                blocks_[i].setIntern(*(new Intern()));
            return;
        }
    }
    std::cout << "There is no job, find another place to beg !!!" << std::endl;
}

void CentralBureaucracy::queueUp(std::string target)
{
    s_queueTargets *tmp = queueTargets_;

    if (queueTargets_ == nullptr)
    {
        queueTargets_ = new s_queueTargets;
        queueTargets_->name = target;
        queueTargets_->next = nullptr;
    }
    else
    {
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = new s_queueTargets;
        tmp->next->name = target;
        tmp->next->next = nullptr;
    }
}

std::string *CentralBureaucracy::dequeueTarget()
{
    s_queueTargets *tmp = queueTargets_;
    std::string *ret = nullptr;

    if (tmp != nullptr)
    {
        queueTargets_ = queueTargets_->next;
        ret = new std::string(tmp->name);
        delete tmp;
    }
    return ret;
}

void CentralBureaucracy::doBureaucracy()
{
    std::string *target;
    std::string formName;
    int i = 0;

    while ((target = dequeueTarget()) != nullptr)
    {
        bool check1 = false;
        bool check2 = false;
        while (blocks_[i].getSigner() == nullptr || blocks_[i].getExecuter() == nullptr)
        {
            if (check1 && check2)
            {
                std::cout << "Not bureaucracy in center, go away!" << std::endl;
                return;
            }

            if (i == 19)
                check1 = true;
            if (i== 19 && check1)
                check2 = true;

            i = (i + 1) % 20;
        }
        
        srand(time(NULL));
        int r = rand() % 3;
        if (r == 0)
            formName = "presidential pardon";
        else if (r == 1)
            formName = "robotomy request";
        else
            formName = "shrubbery creation";
        blocks_[i].doBureaucracy(formName, *target);
        sleep(1);

        check1 = false;
        check2 = false;
        i = (i + 1) % 20;
    }
}