#include <PmergeMe.hpp>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		deque = other.deque;
		vector = other.vector;
	}
	return (*this);
}

template <typename C>
void	first_step(C &container)
{
	size_t	i, j;

	for (i = 0, j = 1; j < container.size(); i+=2, j+=2)
		if (container[i] > container[j])
			std::swap(container[i], container[j]);
}

template <typename C>
void	merge(C &container, size_t first, size_t mid, size_t last)
{
	C		right;
	C		left;
	size_t	r;
	size_t	l;
	size_t	i;

	for (l = 0; l < mid - first + 1; l++)
		left.push_back(container[first + l]);
	for (r = 0; r < last - mid; r++)
		right.push_back(container[mid + r + 1]);
	for (l = 0, r = 0, i = first; l < left.size() && r < right.size(); i++)
	{
		if (left[l] < right[r])
			container[i] = left[l++];
		else
			container[i] = right[r++];
	}
	while (l < left.size())
		container[i++] = left[l++];
	while (r < right.size())
		container[i++] = right[r++];
}


template <typename C>
void	merge_sort(C &container, size_t first, size_t last)
{
	size_t	mid = (first + last) / 2;

	if (first < last)
	{
		merge_sort<C>(container, first, mid);
		merge_sort<C>(container, mid + 1, last);
		merge<C>(container, first, mid, last);
	}
}

template <typename C>
void	second_step(C &container, C &largest)
{
	size_t	i;

	for (i = 1; i < container.size(); i+=2)
		largest.push_back(container[i]);
	merge_sort<C>(largest, 0, largest.size() - 1);
}

template <typename C>
void	third_step(C container, C &largest, C &smallest)
{
	size_t	i;

	for (i = 1; i < container.size(); i+=2)
	{
		if (largest[0] == container[i])
			largest.insert(largest.begin(), container[i - 1]);
		else
			smallest.push_back(container[i - 1]);
	}
	if (container.end() == container.begin() + i)
		smallest.push_back(container[i - 1]);
}

template <typename C>
size_t	group_size(C container, size_t i)
{
	if (i == 0)
		return (0);
	return (std::pow(2, i) - group_size(container, i - 1));
}

template <typename C>
void	binary_search(C &container, size_t left, size_t right, size_t value)
{
	size_t	mid = (right - left) / 2 + left;

	if (left >= right)
	{
		container.insert(container.begin() + left, value);
		return ;
	}
	if (value == container[mid])
	{
		container.insert(container.begin() + mid, value);
		return ;
	}
	if (value < container[mid])
	{
		if (mid == 0)
		{
			container.insert(container.begin(), value);
			return ;
		}
		binary_search(container, left, mid, value);
	}
	else
		binary_search(container, mid + 1, right, value);
}

template <typename C>
void	fourth_step(C &largest, C &smallest)
{
	for (size_t i = 0, j = 1, g_size = group_size(smallest, j); i < smallest.size();
		i += g_size, j++, g_size = group_size(smallest, j))
	{
		if (smallest.begin() + i + g_size < smallest.end())
			std::reverse(smallest.begin() + i, smallest.begin() + i + g_size);
		else
			std::reverse(smallest.begin() + i, smallest.end());
	}
	for (size_t i = 0; i < smallest.size(); i++)
		binary_search(largest, 0, largest.size(), smallest[i]);
}

template <typename C>
void	merge_insert_sort(C &container)
{
	C	largest;
	C	smallest;

	first_step(container);
	second_step(container, largest);
	third_step(container, largest, smallest);
	fourth_step(largest, smallest);
	container = largest;
}

template <typename C>
double	start_timer(C &container)
{
	clock_t	start = clock();
	merge_insert_sort(container);
	clock_t	end = clock();
	return ((static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6);
}

PmergeMe::PmergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				std::cout << "Invalid arguments" << std::endl;
				return ;
			}
		}
		vector.push_back(atoi(argv[i]));
		deque.push_back(atoi(argv[i]));
	}
	std::cout << "Before:\t";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << ' ';
	double	time_v = start_timer(vector);
	double	time_d = start_timer(deque);
	std::cout << std::endl << "After:\t";
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << ' ';
	std::cout << std::endl;
	std::cout <<  TIME << vector.size() << VECTOR << time_v << " us" << std::endl;
	std::cout <<  TIME << deque.size() << DEQUE << time_d << " us" << std::endl;

}