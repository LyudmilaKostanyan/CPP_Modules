#include "../includes/AForm.hpp"

AForm::AForm() : name(), isSigned(false), signedGrade(1), execGrade(1) {}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), execGrade(other.execGrade) {}

AForm::AForm(std::string _name, const int &_signedGrade, const int &_execGrade) : name(_name), isSigned(false), signedGrade(_signedGrade), execGrade(_execGrade)
{
	if (signedGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signedGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getIsSigned() const
{
	return this->isSigned;
}

int	AForm::getSignedGrade() const
{
	return this->signedGrade;
}

int	AForm::getExecGrade() const
{
	return this->execGrade;
}

void	AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void	AForm::setName(const std::string &name)
{
	this->name = name;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

const char *AForm::SignedException::what() const throw()
{
	return ("Form isn't signed");
}

std::ostream	&operator<<(std::ostream &os, const AForm &form)
{
	os << "Form name " << form.getName() << "\nSigned " << form.getIsSigned()
		<< "\nSigned grade " << form.getSignedGrade() << "\nExecute grade "
		<< form.getExecGrade() << std::endl;
	return os;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > signedGrade)
		throw GradeTooLowException();
	isSigned = true;
}

void	AForm::check(Bureaucrat const & executor) const
{
	if (executor.getGrade() > execGrade)
		throw GradeTooLowException();
	if (!isSigned)
		throw SignedException();
}

