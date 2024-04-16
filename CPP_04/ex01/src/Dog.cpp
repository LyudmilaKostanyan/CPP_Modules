#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	std::cout << "Dog Copy constructor called" << std::endl;
	brain = new Brain();
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}
