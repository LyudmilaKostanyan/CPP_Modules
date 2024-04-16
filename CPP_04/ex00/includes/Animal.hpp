#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		Animal			&operator=(const Animal &other);
		void			setType(std::string type);
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif