#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <cstdlib>

# define DATABASE_ERR "Error: could not open database."
# define FILE_ERR "Error: could not open file."

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
};

#endif