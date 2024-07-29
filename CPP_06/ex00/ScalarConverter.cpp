#include "ScalarConverter.hpp"

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

int	check(std::string num)
{
	size_t	point;
	size_t	f_sign;

	point = num.find(".", 0);
	f_sign = num.find("f", 0);
	for (size_t i = 0; i < num.length(); i++)
		if ((!isdigit(num[i]) && i != point && i != f_sign)
			|| (i == 0 && (num[i] == '-' || num[i] == '+')))
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

void	convert_string(std::string num, int type)
{
	double		numb;
	int			int_num;
	float		float_num;
	double		double_num;
	char		char_num;

	if (type == 2 || type == 3)
		numb = atof(num.c_str());
	else
		numb = atoi(num.c_str());
	int_num = static_cast<int>(numb);
	float_num = static_cast<float>(numb);
	double_num = static_cast<double>(numb);
	char_num = static_cast<char>(numb);
	if (!type || num.substr(0, num.find(".", 0)).length() - !isdigit(num[0]) > 10)
		std::cout << "char:\timpossible" << std::endl;
	else if (char_num < 32 || char_num > 126)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t" << "'" << char_num << "'" << std::endl;
	if (!type || num.substr(0, num.find(".", 0)).length() - !isdigit(num[0]) > 10)
		std::cout << "int:\timpossible" << std::endl;
	else
		std::cout << "int:\t" << int_num << std::endl;
	if (num == "-inff" || num == "+inff" || num == "nan")
		std::cout << "float:\tnanf" << std::endl;
	else if (!type || num.substr(0, num.find(".", 0)).length() - !isdigit(num[0]) > 10)
		std::cout << "float:\t" << num << std::endl;
	else
		std::cout << "float:\t"  << std::fixed << std::setprecision(1) << float_num << "f" << std::endl;
	if (num == "-inf" || num == "+inf")
		std::cout << "double:\t" << num << std::endl;
	else if (!type || num.substr(0, num.find(".", 0)).length() - !isdigit(num[0]) > 10)
		std::cout << "double:\tnan" << std::endl;
	else
		std::cout << "double:\t" << std::fixed << std::setprecision(1) << double_num << std::endl;
}

void	ScalarConverter::convert(std::string num)
{
	int	type;

	type = check(num);
	convert_string(num, type);
}
