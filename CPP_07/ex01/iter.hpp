#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	increment(T &i)
{
	i++;
}

template <typename T>
void	decrement(T &i)
{
	i--;
}

template <typename T>
void	print(T &i)
{
	std::cout << i << std::endl;
}

template <typename A>
void iter(A *array, size_t length, void (*func)(A &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif