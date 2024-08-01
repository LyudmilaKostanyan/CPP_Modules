#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <cstdlib>

# define DATABASE "data.csv"
# define DATABASE_ERR "Error: could not open database."
# define FILE_ERR "Error: could not open file."
# define BAD_IN "Error: bad input => "
# define TOO_LARGE "Error: too large a number."
# define NEG_NUM "Error: not a positive number."
# define W_DATA "Error: wrong date."
# define W_VALUE "Error: wrong value."
# define W_FORMAT "Error: wrong format."
# define FILE_HEAD "date | value"


class BitcoinExchange
{
	private:
		std::map<std::string, float> data;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		bool	read_data();
		void	find_date(std::ifstream &file, std::string line);
};

#endif