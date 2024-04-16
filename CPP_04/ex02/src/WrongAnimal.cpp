#include "../includes/WrongAnimal.hpp"

WrongAAnimal::WrongAAnimal()
{
	std::cout << "WrongAAnimal Default constructor called" << std::endl;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "WrongAAnimal Destructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(std::string type)
{
	std::cout << "WrongAAnimal Constructor called" << std::endl;
	setType(type);
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal &other)
{
	std::cout << "WrongAAnimal Copy constructor called" << std::endl;
	*this = other;
}

WrongAAnimal	&WrongAAnimal::operator=(const WrongAAnimal &other)
{
	std::cout << "WrongAAnimal Copy assignment operator called" << std::endl;
	setType(other.type);
	return *this;
}

void	WrongAAnimal::setType(std::string type)
{
	this->type = type;
}

std::string	WrongAAnimal::getType() const
{
	return this->type;
}
