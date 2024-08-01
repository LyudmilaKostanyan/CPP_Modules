#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define TIME "Time to process a range of "
# define VECTOR " elements with std::vector : "
# define DEQUE " elements with std::deque : "

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <iterator>
# include <algorithm>
# include <cmath>
# include <ctime>
# include <sys/time.h>
# include <climits>

class PmergeMe
{
	private:
		std::vector<size_t>	vector;
		std::deque<size_t>	deque;
	public:
		PmergeMe();
		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
};

#endif