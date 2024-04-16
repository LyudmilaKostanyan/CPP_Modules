#ifndef DOG_HPP
# define DOG_HPP

# include "Zoo.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog			&operator=(const Dog &other);
		void		setType(std::string type);
		std::string	getType() const;
		void		makeSound() const;
};

#endif