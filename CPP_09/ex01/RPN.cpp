#include <RPN.hpp>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		nums = other.nums;
	return (*this);
}

bool	operations_handler(std::queue<double> &nums, std::queue<char> &signs, double &num1)
{
	short	num2;
	size_t	i = 0;

	while (signs.size() != 0 && ++i)
	{
		if (i == 1)
		{
			num1 = nums.front();
			nums.pop();
		}
		num2 = nums.front();
		nums.pop();
		if (signs.front() == '+')
			num1 = num1 + num2;
		else if (signs.front() == '-')
			num1 = num1 - num2;
		else if (signs.front() == '*')
			num1 = num1 * num2;
		else if (signs.front() == '/')
		{
			if (num2 == 0)
			{
				std::cout << "Error: division by zero." << std::endl;
				return (false);
			}
			num1 = num1 / num2;
		}
		signs.pop();
	}
	return (true);
}

bool	RPN::argument_hendler(std::string arg)
{
	double	num;
	double	tmp;
	double	num_b;
	size_t	count = 0;

	for (size_t i = 0; i < arg.length(); i++)
	{
		if (arg[i] == ' ')
			continue ;
		if (isdigit(arg[i]))
		{
			tmp = arg[i] - '0';
			count++;
			while (arg[++i] == ' ')
				;
			if (isdigit(arg[i]) && count != 1)
			{
				nums_b.push(tmp);
				nums_b.push(arg[i] - '0');
				while (arg[++i] == ' ')
					;
				if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
					signs_b.push(arg[i]);
				else
					return (false);
				if (!operations_handler(nums_b, signs_b, num_b))
					return (false);
				nums.push(num_b);
			}
			else
			{
				nums.push(tmp);
				i--;
			}
		}
		else if ((arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/') && count)
			signs.push(arg[i]);
		else if (arg[i] != ' ')
			return (false);
	}
	if (nums.size() == 0 || signs.size() == 0 || nums.size() != signs.size() + 1)
		return (false);
	if (!operations_handler(nums, signs, num))
		return (false);
	std::cout << num << std::endl;
	return (true);
}

RPN::RPN(std::string arg)
{
	if (!argument_hendler(arg))
	{
		std::cout << "Wrong type of arguments" << std::endl;
		return ;
	}
}