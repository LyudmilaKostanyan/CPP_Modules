#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string _name, int grade) : name(_name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->setGrade(other.getGrade());
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ": " << bureaucrat.getGrade();
	return os;
}

void	Bureaucrat::increment()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::decrement()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}
