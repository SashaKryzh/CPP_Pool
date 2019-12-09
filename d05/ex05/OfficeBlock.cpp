#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : intern_(nullptr), signingBureaucrat_(nullptr), executingBureaucrat_(nullptr) {}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signing, Bureaucrat *executing)
    : intern_(intern), signingBureaucrat_(signing), executingBureaucrat_(executing) {}

OfficeBlock::~OfficeBlock() {}

void OfficeBlock::setIntern(Intern &intern)
{
    intern_ = &intern;
}

void OfficeBlock::setSigner(Bureaucrat &signing)
{
    signingBureaucrat_ = &signing;
}

void OfficeBlock::setExecutor(Bureaucrat &executing)
{
    executingBureaucrat_ = &executing;
}

Intern *OfficeBlock::getIntern() const
{
    return intern_;
}

Bureaucrat *OfficeBlock::getSigner() const
{
    return signingBureaucrat_;
}

Bureaucrat *OfficeBlock::getExecuter() const
{
    return executingBureaucrat_;
}

void OfficeBlock::doBureaucracy(std::string formName, std::string target)
{
    if (intern_ == nullptr || signingBureaucrat_ == nullptr || executingBureaucrat_ == nullptr)
        throw NotEnoughPersonalInOfficeBlockException();

    Form *f = intern_->makeForm(formName, target);

    if (f == nullptr)
        throw UnknownFormName();

    signingBureaucrat_->signForm(*f);
    executingBureaucrat_->executeForm(*f);
}

const char *OfficeBlock::NotEnoughPersonalInOfficeBlockException::what() const throw()
{
    return "Some personal is missing in the office";
}

const char *OfficeBlock::UnknownFormName::what() const throw()
{
    return "Unknown form name";
}