#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

void	Brain::setIdeas(std::string *type)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = type[i];
}

std::string	*Brain::getType() const
{
	return (std::string *)this->ideas;
}