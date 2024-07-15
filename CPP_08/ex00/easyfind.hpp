#ifndef EASTFIND_HPP
# define EASTFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>

template <typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator i = std::find(container.begin(), container.end(), n);
	if (i == container.end())
		throw std::exception();
	return i;
}

#endif