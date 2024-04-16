#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << std::endl;

	Animal	*asd[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			asd[i] = new Dog();
		else
			asd[i] = new Cat();
	}
	asd[0]->makeSound();
	asd[3]->makeSound();
	for (int i = 0; i < 4; i++)
		delete asd[i];
	return 0;
}