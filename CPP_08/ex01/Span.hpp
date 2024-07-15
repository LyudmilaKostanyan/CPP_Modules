#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private:
		unsigned int		n;
		std::vector<int>	nums;
	public:
		Span();
		~Span();
		Span(Span const &other);
		Span &operator=(Span const &other);
		Span(unsigned int);
		void	addNumber(int);
		void	addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
		int		shortestSpan();
		int		longestSpan();
};

#endif