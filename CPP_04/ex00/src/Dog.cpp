#include "../includes/Zoo.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	setType(other.type);
	return *this;
}

void	Dog::setType(std::string type)
{
	this->type = type;
}

std::string	Dog::getType() const
{
	return this->type;
}

void	Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}
