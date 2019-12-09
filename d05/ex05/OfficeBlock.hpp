#if !defined(OFFICE_BLOCK_HPP)
#define OFFICE_BLOCK_HPP

#include <string>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock
{
private:
    Intern *intern_;
    Bureaucrat *signingBureaucrat_;
    Bureaucrat *executingBureaucrat_;

public:
    OfficeBlock();
    OfficeBlock(Intern *, Bureaucrat *signing, Bureaucrat*executing);
    ~OfficeBlock();

    void setIntern(Intern &);
    void setSigner(Bureaucrat &);
    void setExecutor(Bureaucrat &);

    Intern *getIntern() const;
    Bureaucrat *getSigner() const;
    Bureaucrat *getExecuter() const;

    void doBureaucracy(std::string formName, std::string target);

    struct NotEnoughPersonalInOfficeBlockException : public std::exception
    {
        const char *what() const throw();
    };

    struct UnknownFormName : public std::exception
    {
        const char *what() const throw();
    };
};

#endif // OFFICE_BLOCK_HPP
