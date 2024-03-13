#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &_weapon) : weapon(_weapon)
{
	this->name = name;
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
