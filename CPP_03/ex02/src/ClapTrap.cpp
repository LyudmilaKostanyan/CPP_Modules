#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("noname"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

std::string	ClapTrap::getName()
{
	return name;
}

ClapTrap::ClapTrap(std::string name) : hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	setName(name);
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (hit_points && energy_points)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " died or don't have enough energy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points)
	{
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage" << std::endl;
		if (hit_points - int(amount) >= 0)
			hit_points -= amount;
		else
			hit_points = 0;
	}
	else
		std::cout << "ClapTrap " << name << " died" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points && energy_points)
	{
		std::cout << "ClapTrap " << name << " was repaired for " << amount << " hit points" << std::endl;
		hit_points += amount;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " died or don't have enough energy" << std::endl;
}
