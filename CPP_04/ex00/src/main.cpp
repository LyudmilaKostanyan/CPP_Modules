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

	const WrongAnimal *A = new WrongAnimal();
	const WrongAnimal *B = new WrongCat();

	A->makeSound();
	B->makeSound();
	delete A;
	delete B;

	return 0;
}