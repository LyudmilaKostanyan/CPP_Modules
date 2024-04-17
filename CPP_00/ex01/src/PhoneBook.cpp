#include "../includes/defines.h"
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

void	PhoneBook::setIndex(int index)
{
	this->index = index;
}

void	PhoneBook::check_output_type(std::string *input, int (*check_type)(int), bool *flag)
{
	for (int i = 0; i < (int)input->length(); i++)
		if (!check_type((*input)[i]))
		{
			std::cout << NAME_ERR << std::endl;
			*flag = true;
			break ;
		}
}

std::string	PhoneBook::add_info(const char *output)
{
	bool		flag = true;
	std::string	input;

	while (flag)
	{
		if (!get_input(&input, output))
			continue ;
		flag = false;
		if (!strcmp(output, PHONE) || !strcmp(output, INDEX))
			check_output_type(&input, std::isdigit, &flag);
		else if (strcmp(output, SECRET) && strcmp(output, N_NAME))
			check_output_type(&input, std::isalpha, &flag);
	}
	return (input);
}

void	PhoneBook::add_cont()
{
	index++;
	contact[index % 8].setIndex(index % 8);
	contact[index % 8].setName(add_info(NAME));
	contact[index % 8].setLastname(add_info(L_NAME));
	contact[index % 8].setNickname(add_info(N_NAME));
	contact[index % 8].setPhone(add_info(PHONE));
	contact[index % 8].setSecret(add_info(SECRET));
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
	if (contact[0].getName().empty())
		std::cout << "Phonebook is empty." << std::endl;
	else
	{
		std::cout << std::setw(10) << "index";
		std::cout << '|' << std::setw(10) << "name";
		std::cout << '|' << std::setw(10) << "last name";
		std::cout << '|' << std::setw(10) << "nickname" << std::endl;
	}
	for (int i = 0; i < 8 && !contact[i].getName().empty(); i++)
	{
		std::cout << std::setw(10) << contact[i].getIndex();
		show_info(contact[i].getName());
		show_info(contact[i].getLastname());
		show_info(contact[i].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::show_cont()
{
	std::string	input;
	int			i;

	while (!contact[0].getName().empty())
	{
		input = add_info(INDEX);
		if (input.length() == 1)
		{
			i = std::atoi(input.c_str());
			if (contact[i].getName().empty())
			{
				std::cout << INDEX_ERR << std::endl;
				continue ;
			}
			std::cout << "NAME: " << contact[i].getName() << std::endl;
			std::cout << "LAST NAME: " << contact[i].getLastname() << std::endl;
			std::cout << "NICK NAME: " << contact[i].getNickname() << std::endl;
			std::cout << "PHONE NUMBER: " << contact[i].getPhone() << std::endl;
			std::cout << "DARKEST SECRET: " << contact[i].getSecret() << std::endl;
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
