#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &other);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &other);
		void		setName(std::string name);
		std::string	getName();
		void		attack(const std::string &target);
		void		highFivesGuys();
};

#endif