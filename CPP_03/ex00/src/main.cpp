#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap Jacob("Jacob");
	ClapTrap noname;

	Jacob.attack(noname.getName());
	noname.takeDamage(1);
	noname.beRepaired(5);
	noname.attack(Jacob.getName());
	Jacob.takeDamage(30);
	Jacob.beRepaired(42);
	Jacob.attack(noname.getName());
	noname.attack(Jacob.getName());
	Jacob.takeDamage(10);
	return 0;
}