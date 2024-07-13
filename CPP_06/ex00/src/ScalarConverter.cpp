#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

int	ft_atoi(std::string literal)
{
	long int	num = 0;
	int			sign = 1;
	int			i = 0;

	if (literal[0] == '-')
	{
		sign = -1;
		i++;
	}
	if (literal[0] == '+')
		i++;
	if (literal.length() - i > 10)
		return (0);
	while (literal[i])
		num = num * 10 + (literal[i++] - 48);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (num * sign);
}

int	check_type(std::string num)
{
	size_t	point;
	size_t	f_sign;

	point = num.find(".", 0);
	f_sign = num.find("f", 0);
	for (size_t i = 0; i < num.length(); i++)
		if (!isdigit(num[i]) && i != point && i != f_sign && num[0] != '+' && num[0] != '-')
			return (0);
	if (point != std::string::npos)
	{
		if (f_sign != std::string::npos)
		{
			if (num[num.length() - 1] != 'f')
				return (0);
			return (2);
		}
		return (3);
	}
	return (1);
}

int	convert_to_num(std::string num, int type, int &int_num, int &after_dot)
{
	if (!type || num.substr(0, num.find(".", 0)).length() - !isdigit(num[0]) > 10)
		return (0);
	if (type == 1)
	{
		int_num = ft_atoi(num);
		if (int_num == 0 && num.length() > 1)
			return (0);
		after_dot = 0;
	}
	else if (type == 2)
	{
		int_num = ft_atoi(num.substr(0, num.find(".", 0)));
		if (int_num == 0 && num.substr(0, num.find(".", 0)).length() > 1)
			return (0);
		after_dot = ft_atoi(num.substr(num.find(".", 0) + 1, num.find("f", 0) - num.find(".", 0) - 1));
	}
	else
	{
		int_num = ft_atoi(num.substr(0, num.find(".", 0)));
		if (int_num == 0 && num.substr(0, num.find(".", 0)).length() > 1)
			return (0);
		after_dot = ft_atoi(num.substr(num.find(".", 0) + 1, num.length() - num.find(".", 0) - 1));
	}
	return (1);
}

void	print_number(int int_num, int after_dot, int state)
{
	if (!state)
		std::cout << "char: impossible" << std::endl;
	else if (int_num < 32 || int_num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(int_num) << "'" << std::endl;
	if (!state)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << int_num << std::endl;
	if (!state)
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << int_num << "." << after_dot << "f" << std::endl;
	if (!state)
		std::cout << "double: nan" << std::endl;
	else
		std::cout << "double: " << int_num << "." << after_dot << std::endl;
}

void	ScalarConverter::convert(std::string num)
{
	int	type;
	int	int_num;
	int	after_dot;
	int	state;

	type = check_type(num);
	state = convert_to_num(num, type, int_num, after_dot);
	print_number(int_num, after_dot, state);
}
