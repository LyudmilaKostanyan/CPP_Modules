#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"


int main()
{
	Bureaucrat bureaucrat("A", 1);
	Intern intern;
	AForm* A;

	A = intern.makeForm("shrubbery creation", "A");
	bureaucrat.signForm(*A);
	bureaucrat.executeForm(*A);
	delete A;
	std::cout << std::endl;
	A = intern.makeForm("robotomy request", "B");
	bureaucrat.signForm(*A);
	bureaucrat.executeForm(*A);
	delete A;
	std::cout << std::endl;

	A = intern.makeForm("presidential pardon", "C");
	bureaucrat.signForm(*A);
	bureaucrat.executeForm(*A);
	delete A;
	std::cout << std::endl;

	try
	{
		A = intern.makeForm("SHRUBERRY", "D");
		bureaucrat.signForm(*A);
		bureaucrat.executeForm(*A);
		delete A;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}