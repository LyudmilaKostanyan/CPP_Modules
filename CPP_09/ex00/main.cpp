#include <BitcoinExchange.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << FILE_ERR << std::endl;
		return (1);
	}
	std::string		file_name = argv[1];
	BitcoinExchange	exchange(file_name);
	return (0);
}