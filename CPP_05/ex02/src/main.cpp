#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	try
    {
		Bureaucrat bureaucrat("A", 137);
		ShrubberyCreationForm form("ShrubberyCreationForm");

		bureaucrat.executeForm(form);
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
	    std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("B", 1);
		RobotomyRequestForm form("RobotomyRequestForm");
		bureaucrat.executeForm(form);
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("C", 1);
		PresidentialPardonForm form("PresidentialPardonForm");
		bureaucrat.executeForm(form);
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}