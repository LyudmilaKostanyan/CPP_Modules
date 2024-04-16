#ifndef CAT_HPP
# define CAT_HPP

# include "Zoo.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat			&operator=(const Cat &other);
		void		setType(std::string type);
		std::string	getType() const;
		void		makeSound() const;

};

#endif