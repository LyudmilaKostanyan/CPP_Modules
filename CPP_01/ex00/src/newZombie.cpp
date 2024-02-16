#include "../includes/Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie;
	zombie->setName(name);
	zombie->announce();
	return (zombie);
}