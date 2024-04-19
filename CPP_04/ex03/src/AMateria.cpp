# include "../includes/AMateria.hpp"
# include "../includes/Cure.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	this->type = other.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void	AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "Nothing to done" << std::endl;
}
