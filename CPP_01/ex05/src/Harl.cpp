#include "../includes/Harl.hpp"

Harl::Harl()
{
	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
}

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
	std::string func_names[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
		if (!level.compare(func_names[i]))
			(this->*func[i])();
}
