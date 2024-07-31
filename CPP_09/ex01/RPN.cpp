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

bool	RPN::operations_handler(char arg)
{
	double	num1;
	double	num2;

	num1 = nums.top();
	nums.pop();
	num2 = nums.top();
	nums.pop();
	if (arg == '+')
		nums.push(num2 + num1);
	else if (arg == '-')
		nums.push(num2 - num1);
	else if (arg == '*')
		nums.push(num2 * num1);
	else if (arg == '/')
	{
		if (num1 == 0)
		{
			std::cout << "Error: division by zero." << std::endl;
			return (false);
		}
			nums.push(num2 / num1);
	}
	else
	{
		std::cout << "Error: wrong symbols." << std::endl;
		return (false);
	}
	return (true);
}

bool	RPN::argument_hendler(std::string arg)
{
	bool	state = 0;

	for (size_t i = 0; i < arg.length(); i++)
	{
		state = 0;
		if (arg[i] == ' ')
			continue ;
		if (nums.size() > 2)
		{
			std::cout << "Error: too many numbers." << std::endl;
			return (false);
		}
		if (isdigit(arg[i]))
			nums.push(arg[i] - '0');
		else if (nums.size() < 2)
		{
			std::cout << "Error: not enough numbers or wrong type of arguments." << std::endl;
			return (false);
		}
		else
		{
			if (!operations_handler(arg[i]))
				return (false);
			state = 1;
		}
	}
	if (!state)
		return (false);
	return (true);
}

RPN::RPN(std::string arg)
{
	if (!argument_hendler(arg))
	{
		std::cout << "Wrong type of arguments" << std::endl;
		return ;
	}
	else if (nums.size() != 0 && nums.size() == 1)
		std::cout << nums.top() << std::endl;
	else if (nums.size() != 1)
	{
		nums.pop();
		std::cout << nums.top() << std::endl;
	}
	else
		std::cout << "Error: pleas write expression." << std::endl;
}