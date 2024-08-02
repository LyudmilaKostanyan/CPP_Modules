# include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->materia = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->materia[i])
			delete this->materia[i];
	delete [] this->materia;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	if (!this->materia)
		this->materia = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		if (other.materia[i])
			this->materia[i] = other.materia[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (!this->materia)
		this->materia = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		if (other.materia[i])
			this->materia[i] = other.materia[i];
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] == NULL)
		{
			this->materia[i] = m;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] != NULL && this->materia[i]->getType() == type)
			return (this->materia[i])->clone();
	}
	return NULL;
}

