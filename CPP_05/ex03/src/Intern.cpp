#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int			i;
	AForm		*form = NULL;
	std::string	classes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (i = 0; i < 3; i++)
		if (name == classes[i])
			break ;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw WrongName();
	}
	if (form)
		std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

const char *Intern::WrongName::what() const throw()
{
	return ("Wrong name");
}
