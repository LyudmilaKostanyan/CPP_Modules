#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

void	increment(int &i)
{
	i++;
}

template <typename T>
void	decrement(T &i)
{
	i--;
}

template <typename A>
void iter(A *array, size_t length, void (*func)(A &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif