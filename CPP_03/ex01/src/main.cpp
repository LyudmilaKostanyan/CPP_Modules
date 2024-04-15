#include "../includes/ScavTrap.hpp"

int main(void)
{
	ClapTrap A("A");
	ScavTrap B("B");

	A.attack(B.getName());
	B.takeDamage(10);
	B.attack(A.getName());
	A.takeDamage(1);
	B.guardGate();
	A.attack(B.getName());
	B.takeDamage(90);
	B.attack(A.getName());
	A.takeDamage(20);
	return 0;
}