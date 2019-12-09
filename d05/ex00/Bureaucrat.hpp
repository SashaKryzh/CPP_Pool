#if !defined(BUREAUCRAT_HPP)
#define BUREAUCRAT_HPP

#include <iostream>

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
