#include "defines.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

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

void	PhoneBook::check_output_type(std::string *input, int (*check_type)(int), bool *flag)
{
	for (int i = 0; i < input->length(); i++)
		if (!check_type((*input)[i]))
		{
			std::cout << NAME_ERR << std::endl;
			*flag = true;
			break ;
		}
}

void	PhoneBook::add_info(std::string *input, const char *output)
{
	bool	flag = true;

	while (flag)
	{
		if (!get_input(input, output))
			continue ;
		flag = false;
		if (output == PHONE || output == INDEX)
			check_output_type(input, std::isdigit, &flag);
		else if (output != SECRET)
			check_output_type(input, std::isalpha, &flag);
	}
}

void	PhoneBook::add_cont()
{
	contact[++index % 8].index = (index + 1) % 8;
	add_info(&contact[index % 8].name, NAME);
	add_info(&contact[index % 8].lastname, L_NAME);
	add_info(&contact[index % 8].nickname, N_NAME);
	add_info(&contact[index % 8].phone, PHONE);
	add_info(&contact[index % 8].secret, SECRET);
}

void	show_info(std::string info)
{
	std::cout << '|';
	if (info.length() > 10)
		std::cout.write(info.c_str(), 9) << '.';
	else
		std::cout << std::setw(10) << info;
}

void	PhoneBook::show_table()
{
	if (contact[0].name.empty())
		std::cout << "Phonebook is empty." << std::endl;
	else
	{
		std::cout << std::setw(10) << "index";
		std::cout << '|' << std::setw(10) << "name";
		std::cout << '|' << std::setw(10) << "last name";
		std::cout << '|' << std::setw(10) << "nickname" << std::endl;
	}
	for (int i = 0; i < 8 && !contact[i].name.empty(); i++)
	{
		std::cout << std::setw(10) << contact[i].index;
		show_info(contact[i].name);
		show_info(contact[i].lastname);
		show_info(contact[i].nickname);
		std::cout << std::endl;
	}
}

void	PhoneBook::show_cont()
{
	std::string	input;

	while (!contact[0].name.empty())
	{
		add_info(&input, INDEX);
		if (input.length() == 1)
		{
			index = std::stoi(input);
			if (contact[index].name.empty())
			{
				std::cout << INDEX_ERR << std::endl;
				continue ;
			}
			std::cout << "NAME: " << contact[index].name << std::endl;
			std::cout << "LAST NAME: " << contact[index].lastname << std::endl;
			std::cout << "NICK NAME: " << contact[index].nickname << std::endl;
			std::cout << "PHONE NUMBER: " << contact[index].phone << std::endl;
			std::cout << "DARKEST SECRET: " << contact[index].secret << std::endl;
			break ;
		}
		else
			std::cout << INDEX_ERR << std::endl;
	}
}

void	PhoneBook::search_cont()
{
	std::string	input;

	show_table();
	show_cont();
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
	while (check_input(&phonebook, input))
		;
	return (0);
}