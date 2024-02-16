#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "str: " << &str << ", " << str << std::endl;
	std::cout << "stringPTR: " << stringPTR << ", " << *stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << ", " << stringREF << std::endl;

	return (0);
}