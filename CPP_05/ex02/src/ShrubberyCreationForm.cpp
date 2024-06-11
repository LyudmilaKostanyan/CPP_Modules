# include "../src/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &_target) : AForm("ShrubberyCreationForm", 145, 137), target(_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}


