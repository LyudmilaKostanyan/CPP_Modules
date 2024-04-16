#include "../includes/Animal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal Constructor called" << std::endl;
	setType(type);
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = other;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
	setType(other.type);
	return *this;
}

void	AAnimal::setType(std::string type)
{
	this->type = type;
}

std::string	AAnimal::getType() const
{
	return this->type;
}

