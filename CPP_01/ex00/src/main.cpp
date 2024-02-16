#include "../includes/Zombie.hpp"

int	main()
{
	std::string	name;
	Zombie		*zombie;

	std::cout << "Ender zombie's name: ";
	getline(std::cin, name);
	zombie = newZombie(name);
	randomChump(name);
	delete zombie;
	return (0);
}