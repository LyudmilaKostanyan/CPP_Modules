#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &other);
		AAnimal			&operator=(const AAnimal &other);
		void			setType(std::string type);
		std::string		getType() const;
		virtual void	makeSound() const = 0;
};
   
#endif