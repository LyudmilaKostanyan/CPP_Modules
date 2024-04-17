#include "../includes/defines.h"
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

bool	get_input(std::string *input, const char *output)
{
	std::cout << output;
	std::getline(std::cin, *input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::cin.clear();
		clearerr(stdin);
		return (false);
	}
	else if (!(*input)[0])
		return (false);
	return (true);
}

int	check_input(PhoneBook *phonebook, std::string input)
{

	if (!get_input(&input, START))
		return (1);
	if (input == "ADD")
		phonebook->add_cont();
	else if (input == "SEARCH")
		phonebook->search_cont();
	else if (input == "EXIT")
		return (0);
	else if (input.size())
		std::cout << W_CMD << std::endl;
	return (1);
}

int	main()
{
	PhoneBook phonebook;
	std::string input;

	phonebook.setIndex(-1);
	while (check_input(&phonebook, input))
		;
	return (0);
}