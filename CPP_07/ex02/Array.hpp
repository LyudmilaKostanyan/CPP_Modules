#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T				*array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();
		class IndexException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		T&		operator[](int index);
		const T	&operator[](int index) const;
		unsigned int	size() const;
};

# include "Array.tpp"

#endif