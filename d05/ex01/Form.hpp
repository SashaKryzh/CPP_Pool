#if !defined(FORM_HPP)
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
    const std::string name_;
    bool signed_;

    const int gradeToSign_;
    const int gradeToExecute_;

public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    ~Form();

    Form(const Form &);
    Form &operator=(const Form &);

    void beSigned(const Bureaucrat &);

    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    struct GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    struct GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif // FORM_HPP
