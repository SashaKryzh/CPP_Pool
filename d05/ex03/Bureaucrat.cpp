#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
    if (grade_ < 1)
        throw GradeTooHighException();
    else if (grade_ > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name_(src.name_)
{
    operator=(src);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        grade_ = src.grade_;
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

void Bureaucrat::incrementGrade()
{
    if (grade_ == 1)
        throw GradeTooHighException();
    grade_--;
}

void Bureaucrat::decrementGrade()
{
    if (grade_ == 150)
        throw GradeTooLowException();
    grade_++;
}

void Bureaucrat::signForm(Form &f) const
{
    try
    {
        f.beSigned((const Bureaucrat) * this);
        std::cout << name_ << " signs " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name_ << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(Form const &f)
{
    try
    {
        f.execute((const Bureaucrat) * this);
        std::cout << name_ << " executes " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name_ << " cannot execute " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}