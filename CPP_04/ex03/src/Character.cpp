# include "../includes/Character.hpp"

Character::Character()
{
	this->name = "noname";
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	delete [] this->inventory;
}

Character::Character(std::string const &name)
{
	this->name = name;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	this->name = other.name;
	if (!this->inventory)
		this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i];
}

Character	&Character::operator=(const Character &other)
{
	this->name = other.name;
	if (!this->inventory)
		this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i];
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
	else
		std::cout << "Wrong arguments" << std::endl;
}

