#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(void)
{
	ClapTrap A("A");
	FragTrap B("B");

	A.attack(B.getName());
	B.takeDamage(10);
	B.attack(A.getName());
	A.takeDamage(1);
	A.attack(B.getName());
	B.takeDamage(90);
	B.attack(A.getName());
	A.takeDamage(20);
	B.highFivesGuys();
	return 0;
}