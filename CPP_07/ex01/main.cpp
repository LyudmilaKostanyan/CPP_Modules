#include "iter.hpp"

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	iter(array, 5, increment);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	char array2[] = {'b', 'c', 'd', 'e'};
	iter(array2, 4, decrement);
	for (int i = 0; i < 4; i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;
	return 0;
}
