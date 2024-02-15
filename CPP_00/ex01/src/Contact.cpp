#include "../includes/defines.h"
#include "../includes/Contact.hpp"

int	Contact::getIndex()
{
	return (index);
}

std::string	Contact::getName()
{
	return (name);
}

std::string	Contact::getLastname()
{
	return (lastname);
}

std::string	Contact::getNickname()
{
	return (nickname);
}

std::string	Contact::getPhone()
{
	return (phone);
}

std::string	Contact::getSecret()
{
	return (secret);
}

void	Contact::setIndex(int index)
{
	this->index = index;
}

void	Contact::setName(std::string name)
{
	this->name = name;
}

void	Contact::setLastname(std::string lastname)
{
	this->lastname = lastname;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhone(std::string phone)
{
	this->phone = phone;
}

void	Contact::setSecret(std::string secret)
{
	this->secret = secret;
}