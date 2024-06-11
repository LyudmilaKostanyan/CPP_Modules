#include "../includes/Form.hpp"

int	main()
{
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 1);
		Form form("form", 3, 5);
		bureaucrat.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 4);
		Form form("form", 3, 5);
		bureaucrat.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;

}
