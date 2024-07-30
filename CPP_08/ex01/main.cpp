#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	{
		Span s;
		try
		{
			s.addNumber(6);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		Span s(5);
		std::vector<int> numbers;
		for (size_t i = 0; i < 5; i++)
			numbers.push_back(i + 1);
		s.addNumber(numbers.begin(), numbers.end());
		try
		{
			s.addNumber(6);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		Span s(4);
		std::vector<int> numbers;
		for (size_t i = 0; i < 4; i++)
			numbers.push_back(i + 1);
		try
		{
			s.addNumber(numbers.begin(), numbers.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		Span s(10001);

		try
		{
			for (int i = 0; i < 10001; i++)
				s.addNumber(i);
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
