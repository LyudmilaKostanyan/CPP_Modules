#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Zoo.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat	&operator=(const WrongCat &other);
		void		setType(std::string type);
		std::string	getType() const;
		void		makeSound() const;

};

#endif