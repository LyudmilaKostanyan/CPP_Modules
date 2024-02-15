#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include "defines.h"

class PhoneBook
{
	private:
		int			index;
		Contact		contact[8];
		std::string	add_info(const char *);
		void		check_output_type(std::string *, int (*)(int), bool *);
		void		show_table();
		void		show_cont();
	public:
		void		setIndex(int);
		void		add_cont();
		void		search_cont();
};

#endif