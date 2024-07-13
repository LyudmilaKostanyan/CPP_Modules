#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <ctype.h>
# include <limits.h>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
	public:
		static void		convert(std::string literal);

};

struct Float
{
	std::string	b_point;
	std::string	a_point;
};

std::string	check_int(std::string literal);
Float		check_float(std::string literal);
int			ft_atoi(std::string literal);

#endif