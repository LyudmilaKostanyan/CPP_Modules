#include "../includes/Zoo.hpp"

int	main()
{
	const Animal *A = new Animal();
	const Animal *B = new Dog();
	const Animal *C = new Cat();

	std::cout << B->getType() << " " << std::endl;
	std::cout << C->getType() << " " << std::endl;
	A->makeSound();
	B->makeSound();
	C->makeSound();
	delete A;
	delete B;
	delete C;

	const WrongAnimal *D = new WrongAnimal();
	const WrongAnimal *E = new WrongCat();

	D->makeSound();
	E->makeSound();
	delete D;
	delete E;

	return 0;
}