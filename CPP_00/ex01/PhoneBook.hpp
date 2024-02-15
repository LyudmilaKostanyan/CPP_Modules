#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		short	index = -1;
		Contact	contact[8];
		void	add_info(std::string *, const char *);
		void	check_output_type(std::string *, int (*)(int), bool *);
		void	show_table();
		void	show_cont();
	public:
		void	add_cont();
		void	search_cont();
};

#endif