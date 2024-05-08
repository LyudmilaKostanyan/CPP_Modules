#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	A("A", 150);
	Bureaucrat	B("B", 1);

	try
	{
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