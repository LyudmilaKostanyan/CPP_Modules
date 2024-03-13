#include "../includes/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << DEBUG << std::endl;
}

void	Harl::info()
{
	std::cout << INFO << std::endl;
}

void	Harl::warning()
{
	std::cout << WARNING << std::endl;
}

void	Harl::error()
{
	std::cout << ERROR << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	std::string func_names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < 4; i++)
		if (!level.compare(func_names[i]))
			break ;
	switch (i)
	{
		case 0:
			this->debug();
			break ;
		case 1:
			this->info();
			break ;
		case 2:
			this->warning();
			break ;
		case 3:
			this->error();
			break ;
		default:
			std::cout << COMPLAINT << std::endl;
			break ;
	}
}
