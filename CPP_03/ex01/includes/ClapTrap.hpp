#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		int				hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		ClapTrap();
		ClapTrap(ClapTrap &other);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &other);
		void		setName(std::string name);
		std::string	getName();
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif