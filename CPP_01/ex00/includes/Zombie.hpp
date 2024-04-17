#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string);
		~Zombie();
		void	announce(void);
		void	setName(std::string);

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
