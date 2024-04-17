#include "../includes/Zombie.hpp"

int	main()
{
	std::string	name;
	std::string	count;
	Zombie		*horde;

	std::cout << "Enter zombie name: ";
	getline(std::cin, name);
	std::cout << "Enter number of zombies: ";
	getline(std::cin, count);
	horde = zombieHorde(atoi(count.c_str()), name);
	for (int i = 0; i < atoi(count.c_str()); i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}