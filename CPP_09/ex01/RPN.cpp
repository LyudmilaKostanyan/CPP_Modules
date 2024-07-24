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

RPN::RPN(std::string arg)
{
// 	for (int i = 0; i < arg.length(); i++)
// 	{
// 		if (arg[i] != ' ' || arg[i] != '+' || arg[i] != '-' || arg[i] != '*'
// 			|| arg[i] != '/' || (arg[i] >= '0' && arg[i] <= '9'))
// 		{
// 			std::cout << "Error: wrong symbols." << std::endl;
// 			return ;
// 		}
// 	}

	double	num1;
	double	num2;

	for (int i = 0; i < arg.length(); i++)
	{
		while (arg[i] == ' ')
			i++;
		if (isdigit(arg[i]))
			nums.push(arg[i] - '0');
		else if (nums.size() < 2)
		{
			std::cout << "Error: not enough numbers." << std::endl;
			return ;
		}
		else
		{
			num1 = nums.top();
			nums.pop();
			num2 = nums.top();
			nums.pop();
			if (arg[i] == '+')
				nums.push(num2 + num1);
			else if (arg[i] == '-')
				nums.push(num2 - num1);
			else if (arg[i] == '*')
				nums.push(num2 * num1);
			else if (arg[i] == '/')
			{
				if (num1 == 0)
				{
					std::cout << "Error: division by zero." << std::endl;
					return ;
				}
				nums.push(num2 / num1);
			}
			else
			{
				std::cout << "Error: wrong symbols." << std::endl;
				return ;
			}
		}
	}
	std::cout << nums.top() << std::endl;
}