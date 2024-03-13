#include "../includes/Harl.hpp"

int	main()
{
	Harl		harl;
	std::string	input;

	while (input.compare("EXIT"))
	{
		std::cout << OUTPUT;
		std::getline(std::cin, input);
		harl.complain(input);
	}
	return (0);
}