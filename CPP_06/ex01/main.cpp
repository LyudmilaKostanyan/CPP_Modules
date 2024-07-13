#include "Serializer.hpp"

int	main()
{
	Data	data, *ptr;

	data.num = -26;
	data.c = 'a';
	data.f = 73.19;
	data.state = true;
	data.std = "Hi";
	ptr = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << "int: " << ptr->num << std::endl;
	std::cout << "char: " << ptr->c << std::endl;
	std::cout << "float: " << ptr->f << std::endl;
	std::cout << "bool: " << ptr->state << std::endl;
	std::cout << "std: " << ptr->std << std::endl;
	return (0);
}