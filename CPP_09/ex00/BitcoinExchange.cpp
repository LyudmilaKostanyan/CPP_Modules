#include <BitcoinExchange.hpp>

bool	check_value(std::string value)
{
	size_t	i = -1;

	if (value.find(".") != value.rfind("."))
		return (false);
	while (++i < value.length())
	{
		if (i == 0 && (value[i] == '-' || value[i] == '+'))
			continue ;
		if (value[i] == '.')
			continue ;
		if (value[i] < '0' || value[i] > '9')
			return (false);
	}
	return (true);
}

bool	check_key(std::string key)
{
	if (key.length() != 10)
		return (false);
	short	year = atoi(key.substr(0, 4).c_str());
	short	month = atoi(key.substr(5, 2).c_str());
	short	day = atoi(key.substr(8, 2).c_str());
	if (year < 2009 || year > 2022)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || (((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1)) && day > 30)
		|| (month == 2 && (((year - 2008) / 4 == 0 && day > 28) || day > 29)) || day > 31)
			return (false);
	return (true);
}

bool	check_line(std::string line, size_t pipe, std::string key, float value)
{
	if (line.empty() || pipe == std::string::npos
		|| (line[pipe - 1] && line[pipe - 1] != ' ')
		|| (line[pipe + 1] && line[pipe + 1] != ' '))
	{
		std::cerr << BAD_IN << line << std::endl;
		return (false);
	}
	if ((value == 0 && line.substr(line.find("|") + 1, line.size()
		- line.find("|") - 1).length() > 9) || value > 1000)
	{
		std::cerr << TOO_LARGE << std::endl;
		return (false);
	}
	if (value <= 0)
	{
		std::cerr << NEG_NUM << std::endl;
		return (false);
	}
	if (!check_key(key))
	{
		std::cerr << W_DATA << std::endl;
		return (false);
	}
	if (!check_value(line.substr(pipe + 2, line.size() - pipe - 1)))
	{
		std::cerr << W_VALUE << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::read_data()
{
	std::ifstream	database(DATABASE);
	std::string		line;

	if (!database.is_open())
	{
		std::cerr << FILE_ERR << std::endl;
		return (false);
	}
	while (std::getline(database, line))
		data[line.substr(0, line.find(","))] = atof((line.substr(line.find(",")
			+ 1, line.size() - line.find(",") - 1)).c_str());
	database.close();
	return (true);
}

void	BitcoinExchange::find_date(std::ifstream &file, std::string line)
{
	std::string	key;
	float		value;
	int			pipe;
	short		year;
	short		month;
	short		day;

	while (std::getline(file, line) && line.length() > 0)
	{
		pipe = line.find("|");
		key = line.substr(0, pipe - 1);
		value = atof((line.substr(pipe + 2, line.size() - pipe - 1)).c_str());
		if (check_line(line, pipe, key, value))
		{
			std::string	_key = key;
			while (data.find(_key) == data.end() && key.substr(0, 4) != "2008")
			{
				day = atoi(_key.substr(8, 2).c_str());
				month = atoi(_key.substr(5, 2).c_str());
				year = atoi(_key.substr(0, 4).c_str());
				if (day > 0)
					day--;
				else if (month > 1)
				{
					month--;
					day = 31;
				}
				else if (year > 2009)
				{
					year--;
					month = 12;
					day = 31;
				}
				if (day < 10 && month > 9)
					_key = std::to_string(year) + "-" + std::to_string(month) + "-0" + std::to_string(day);
				else if (day < 10 && month < 10)
					_key = std::to_string(year) + "-0" + std::to_string(month) + "-0" + std::to_string(day);
				else if (day > 9 && month < 10)
					_key = std::to_string(year) + "-0" + std::to_string(month) + "-" + std::to_string(day);
				else
					_key = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
			}
			std::cout << key << " => " << value << " = " << value * data[_key] << std::endl;
		}
	}
}

BitcoinExchange::BitcoinExchange(std::string file_name)
{
	std::ifstream	file(file_name.c_str());
	std::string		line;

	if (!read_data())
		return ;
	if (!file.is_open())
	{
		std::cerr << FILE_ERR << std::endl;
		return ;
	}
	std::getline(file, line);
	if (line != FILE_HEAD)
	{
		std::cerr << W_FORMAT << std::endl;
		return ;
	}
	find_date(file, line);
	file.close();
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		data.clear();
		data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}