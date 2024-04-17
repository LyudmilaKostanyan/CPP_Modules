#include "../includes/Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	input;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	input = argv[1];
	harl.complain(input);
	return (0);
}