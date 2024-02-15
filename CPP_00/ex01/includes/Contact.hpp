#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "defines.h"

class Contact
{
	private:
		int			index;
		std::string	name;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
	public:
		int			getIndex();
		std::string	getName();
		std::string	getLastname();
		std::string	getNickname();
		std::string	getPhone();
		std::string	getSecret();
		void		setIndex(int index);
		void		setName(std::string name);
		void		setLastname(std::string lastname);
		void		setNickname(std::string nickname);
		void		setPhone(std::string phone);
		void		setSecret(std::string secret);

};

#endif