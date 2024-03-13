#ifndef HARL_HPP
# define HARL_HPP

# define DEBUG "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!"
# define INFO "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!"
# define WARNING "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
# define ERROR "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now."
# define OUTPUT "Choose level - debug, info, warinig, error, or you can EXIT: "
# define COMPLAINT "[ Probably complaining about insignificant problems ]"

# include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void	complain(std::string);
		Harl();
		~Harl();
};

#endif