# include "../includes/AForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		this->target = other.target;
	}
	return *this;
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	this->target = target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	file;

	check(executor);
	std::string		file_name = target + "_shrubbery";
	file.open(file_name.c_str(), std::ios::trunc);
	file << TREE;
}


