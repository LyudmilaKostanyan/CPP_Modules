#include "../includes/Form.hpp"

Form::Form() : name(), isSigned(false), signedGrade(1), execGrade(1) {}

Form::~Form() {}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), execGrade(other.execGrade) {}

Form::Form(std::string _name, const int &_signedGrade, const int &_execGrade) : name(_name), isSigned(false), signedGrade(_signedGrade), execGrade(_execGrade)
{
	if (signedGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signedGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getIsSigned() const
{
	return this->isSigned;
}

int	Form::getSignedGrade() const
{
	return this->signedGrade;
}

int	Form::getExecGrade() const
{
	return this->execGrade;
}

void	Form::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "Form name " << form.getName() << "\nSigned " << form.getIsSigned()
		<< "\nSigned grade " << form.getSignedGrade() << "\nExecute grade "
		<< form.getExecGrade() << std::endl;
	return os;
}

// void	Form::beSigned(Bureaucrat &bureaucrat)
// {
// 	if (bureaucrat.getGrade() > signedGrade)
// 		throw GradeTooLowException();
// 	isSigned = true;
// }
