#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "noname";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

void	ScavTrap::setName(std::string name)
{
	this->name = name;
}

std::string	ScavTrap::getName()
{
	return name;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	setName(name);
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hit_points && energy_points)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
			<< attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ScavTrap " << name << " died or don't have enough energy" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (hit_points)
		std::cout << "ScavTrap " << this->name << " activated guard gate!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " died" << std::endl;
}
