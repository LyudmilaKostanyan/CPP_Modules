#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <Array.hpp>

template <typename T>
Array<T>::Array() : size(0), array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int size)
{
	this->size = size;
	array = new T[size];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->size = other.size;
	array = new T[other.size];
	for (unsigned int i = 0; i < other.size; i++)
			array[i] = other.array[i];
}

template <typename T>
Array &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (array)
			delete [] array;
		this->size = size;
		array = new T[n];
		for (unsigned int i = 0; i < other.size; i++)
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
	if (index < 0 || index >= size)
		throw IndexException();
	return array[index];
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= size)
		throw IndexException();
	return array[index];
}

const char *Array::IndexException::what() const throw()
{
	return ("Index out of range");
}

#endif