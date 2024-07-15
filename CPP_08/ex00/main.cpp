#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> _list = {1, 2, 3, 4, 5};

	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	for (std::list<int>::iterator i = _list.begin(); i != _list.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "vec 5: " << *easyfind(vec, 5) << std::endl;
	std::cout << "vec 2: " << *easyfind(vec, 2) << std::endl;
	std::cout << "vec 4: " << *easyfind(vec, 4) << std::endl;
	std::cout << "list 5: " << *easyfind(_list, 5) << std::endl;
	std::cout << "list 2: " << *easyfind(_list, 2) << std::endl;
	std::cout << "list 4: " << *easyfind(_list, 4) << std::endl;

	std::cout << "vec 300: ";
	try
	{
		std::cout << *easyfind(vec, 300) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	std::cout << "list 300: ";
	try
	{
		std::cout << *easyfind(_list, 300) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return 0;
}