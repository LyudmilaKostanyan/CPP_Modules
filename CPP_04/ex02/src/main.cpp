#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main()
{
	AAnimal	*asd[4];

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