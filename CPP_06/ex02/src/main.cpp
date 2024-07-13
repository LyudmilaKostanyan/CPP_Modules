#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base() {}

Base	*generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int num = std::rand() % 3;

	switch (num)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void	identify(Base *p)
{
	A *a;
	B *b;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	if (a)
		std::cout << "It's class A" << std::endl;
	else if (b)
		std::cout << "It's class B" << std::endl;
	else
		std::cout << "It's class C" << std::endl;
}

void	identify(Base &p)
{
	A	*a;
	B	*b;

	a = dynamic_cast<A *>(&p);
	b = dynamic_cast<B *>(&p);
	if (a)
		std::cout << "It's class A" << std::endl;
	else if (b)
		std::cout << "It's class B" << std::endl;
	else
		std::cout << "It's class C" << std::endl;
}

int		main(void)
{
	Base	*base = generate();
	C		*c = new(C);

	identify(base);
	identify(&*base);
	identify(c);
	identify(&*c);
	delete base;
	delete c;
}