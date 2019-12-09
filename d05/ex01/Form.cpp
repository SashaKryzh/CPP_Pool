#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name_(name), signed_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
    if (gradeToSign_ > 150 || gradeToExecute_ > 150)
        throw GradeTooLowException();
    else if (gradeToSign_ < 1 || gradeToExecute_ < 1)
        throw GradeTooHighException();
}

Form::~Form() {}

Form::Form(const Form &src) : name_(src.name_), gradeToSign_(src.gradeToSign_), gradeToExecute_(src.gradeToExecute_)
{
    operator=(src);
}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        signed_ = src.signed_;
    }
    return *this;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    signed_ = true;
}

std::string Form::getName() const
{
    return name_;
}

bool Form::isSigned() const
{
    return signed_;
}

int Form::getGradeToSign() const
{
    return gradeToSign_;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute_;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
    os << src.getName()
       << ", signed = " << src.isSigned()
       << ", toSign = " << src.getGradeToSign()
       << ", toExecute = " << src.getGradeToExecute()
       << std::endl;
    return os;
}