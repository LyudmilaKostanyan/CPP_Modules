#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->n = other.n;
		this->nums.reserve(n);
	}
	return *this;
}

Span::Span(unsigned int n)
{
	this->n = n;
	this->nums.reserve(n);
}

void	Span::addNumber(int num)
{
	if (!nums.capacity() || this->n == this->nums.size())
		throw std::exception();
	this->nums.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	// std::cout << nums.capacity() << std::endl;
	if (this->n < std::distance(begin, end))
		throw std::exception();
	this->nums.insert(this->nums.end(), begin, end);
}

int	Span::longestSpan()
{
	if (nums.empty())
		throw std::exception();
	return *std::max_element(nums.begin(), nums.end()) - *std::min_element(nums.begin(), nums.end());
}

int	Span::shortestSpan()
{
	std::vector<int>	tmp(nums);
	int					min;

	if (nums.empty())
		throw std::exception();
	std::sort(tmp.begin(), tmp.end());
	min = tmp[1] - tmp[0];
	for (int i = 1; i < tmp.size() - 1; i++)
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	return min;
}


