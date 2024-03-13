#include "../includes/Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string type)
{
	setType(type);
}

std::string	&Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
