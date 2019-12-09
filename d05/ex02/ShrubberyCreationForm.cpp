#include <fstream>
#include <sstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form(target, "ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src)
{
    operator=(src);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkIfAllowedToExecute(executor);

    std::ofstream fs;
    fs.open(getTarget() + "_shrubbery", std::ios::app);
    if (fs.is_open() == false)
        return;

    std::stringstream ss;
    ss << "    _\\/_\n";
    ss << "     /\\\n";
    ss << "     /\\\n";
    ss << "    /  \\\n";
    ss << "    /~~\\o\n";
    ss << "   /o   \\\n";
    ss << "  /~~*~~~\\\n";
    ss << " o/    o \\\n";
    ss << " /~~~~~~~~\\\n";
    ss << "/__*_______\\\n";
    ss << "     ||\n";
    ss << "   \\====/\n";
    ss << "    \\__/\n";

    fs << ss.str();
    fs.close();
}