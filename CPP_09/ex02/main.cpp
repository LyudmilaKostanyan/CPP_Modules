#include <PmergeMe.hpp>

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Too few arguments" << std::endl;
		return (1);
	}
	PmergeMe	pmm(argv);
}