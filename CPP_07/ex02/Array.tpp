#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int size)
{
	this->_size = size;
	array = new T[size];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->_size = other._size;
	array = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
			array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (array)
			delete [] array;
		this->_size = _size;
		array = new T[_size];
		for (unsigned int i = 0; i < other._size; i++)
			array[i] = other.array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (array)
		delete [] array;
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || index >= _size)
		throw IndexException();
	return array[index];
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= _size)
		throw IndexException();
	return array[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}

#endif