#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAAnimal("Wrong Animal")
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	setType(other.type);
	return *this;
}

void	WrongCat::setType(std::string type)
{
	this->type = type;
}

std::string	WrongCat::getType() const
{
	return this->type;
}

void	WrongCat::makeSound() const
{
	std::cout << "WRONG MEOW" << std::endl;
}
