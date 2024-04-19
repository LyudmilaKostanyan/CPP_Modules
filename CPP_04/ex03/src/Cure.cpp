# include "../includes/Cure.hpp"
# include "../includes/ICharacter.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::~Cure() {}

Cure::Cure(const Cure &other) : AMateria(other) {}

Cure	&Cure::operator=(const Cure &other)
{
	this->type = other.type;
	return *this;
}

AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
