#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange()
{

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
	if (day < 1 || (((month <= 7 && month % 2 == 1) || (month > 7 && month % 2 == 0)) && day > 30)
		|| (month == 2 && (((year - 2008) / 4 == 0 && day > 28) || day > 29)) || day > 31)
			return (false);
	return (true);
}

bool	check_line(std::string line, int pipe, std::string key, float value)
{
	if (line.empty() || pipe == std::string::npos
		|| (line[pipe - 1] && line[pipe - 1] != ' ')
		|| (line[pipe + 1] && line[pipe + 1] != ' '))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	if ((value == 0 && line.substr(line.find("|") + 1, line.size() - line.find("|") - 1).length() > 9) || value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (!check_key(key))
	{
		std::cerr << "Error: wrong date." << std::endl;
		return (false);
	}
	return (true);
}

BitcoinExchange::BitcoinExchange(std::string file_name)
{
	std::ifstream	database("data.csv");

	if (!database.is_open())
	{
		std::cerr << FILE_ERR << std::endl;
		return ;
	}
	std::string	line;
	while (std::getline(database, line))
		data[line.substr(0, line.find(","))] = atof((line.substr(line.find(",")
			+ 1, line.size() - line.find(",") - 1)).c_str());
	database.close();

	std::ifstream	file(file_name);

	if (!file.is_open())
	{
		std::cerr << FILE_ERR << std::endl;
		return ;
	}
	int		pipe;
	std::string	key;
	float	value;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: wrong format." << std::endl;
		return ;
	}
	while (std::getline(file, line))
	{
		pipe = line.find("|");
		key = line.substr(0, pipe - 1);
		value = atof((line.substr(pipe + 2, line.size() - pipe - 1)).c_str());
		if (check_line(line, pipe, key, value))
		{
			std::string	_key = key;
			while (data.find(_key) == data.end() && key.substr(0, 4) != "2008")
			{
				if (atoi(_key.substr(8, 2).c_str()) > 0)
					_key = _key.substr(0, 8) + "0" + std::to_string(atoi(_key.substr(8, 2).c_str()) - 1);
				else
				{
					if (atoi(_key.substr(5, 2).c_str()) > 0 && std::to_string(atoi(_key.substr(5, 2).c_str()) - 1).length() != 2)
						_key = _key.substr(0, 5) + "0" + std::to_string(atoi(_key.substr(5, 2).c_str()) - 1) + "-31";
					else if (atoi(_key.substr(5, 2).c_str()) > 0)
						_key = _key.substr(0, 5) + std::to_string(atoi(_key.substr(5, 2).c_str()) - 1) + "-31";
					else
						_key = std::to_string(atoi(_key.substr(0, 4).c_str()) - 1) + "-12-31";
				}
			}
			// std::cout << "asdasdasd: " << _key << std::endl;
			std::cout << key << " => " << value << " = " << value * data[_key] << std::endl;
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}