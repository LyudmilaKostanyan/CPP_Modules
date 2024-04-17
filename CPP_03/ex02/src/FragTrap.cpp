#include "../includes/FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "noname";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

void	FragTrap::setName(std::string name)
{
	this->name = name;
}

std::string	FragTrap::getName()
{
	return name;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	setName(name);
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (hit_points && energy_points)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing "
			<< attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "FragTrap " << name << " died or don't have enough energy" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (hit_points)
		std::cout << "FragTrap " << name << " called high five guys" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " died" << std::endl;
}