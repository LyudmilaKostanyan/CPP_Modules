#include "../includes/Zoo.hpp"

int	main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();

    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    const WrongAnimal *wa = new WrongAnimal();
    const WrongAnimal *wc = new WrongCat();

    wa->makeSound();
    wc->makeSound();

    delete wa;
    delete wc;

    return 0;
}