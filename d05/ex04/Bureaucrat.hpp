#if !defined(BUREAUCRAT_HPP)
#define BUREAUCRAT_HPP

#include <iostream>

#include "Form.hpp"
class Form;

class Bureaucrat
{
private:
    const std::string name_;
    int grade_;

public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();

    Bureaucrat(const Bureaucrat &);
    Bureaucrat &operator=(const Bureaucrat &);

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form &) const;
    void executeForm(Form const & form);

    struct GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    struct GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif // BUREAUCRAT_HPP
