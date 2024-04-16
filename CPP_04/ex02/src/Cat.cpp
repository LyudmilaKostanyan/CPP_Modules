#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	brain = new Brain();
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal("Cat")
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
	brain = new Brain();
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}
