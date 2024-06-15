#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	A("A", 150);
		std::cout << A << std::endl;
		A.decrement();
		std::cout << A << std::endl;
		A.increment();
		std::cout << A << std::endl;
		A.increment();
		std::cout << A << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		Bureaucrat	B("B", 1);
		std::cout << B << std::endl;
		B.increment();
		std::cout << B << std::endl;
		B.decrement();
		std::cout << B << std::endl;
		B.decrement();
		std::cout << B << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

}