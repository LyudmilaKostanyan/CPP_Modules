#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAAnimal
{
	protected:
		std::string	type;
	public:
		WrongAAnimal();
		virtual ~WrongAAnimal();
		WrongAAnimal(std::string type);
		WrongAAnimal(const WrongAAnimal &other);
		WrongAAnimal	&operator=(const WrongAAnimal &other);
		void			setType(std::string type);
		std::string		getType() const;
		virtual void	makeSound() const = 0;
};

#endif