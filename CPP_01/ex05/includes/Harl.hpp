#ifndef HARL_HPP
# define HARL_HPP

# define DEBUG "\033[1;31mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m"
# define INFO "\033[1;31mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m"
# define WARNING "\033[1;31mI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\033[0m"
# define ERROR "\033[1;31mThis is unacceptable! I want to speak to the manager now.\033[0m"
# define OUTPUT "Choose level - debug, info, warinig, error, or you can EXIT: "

# include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	(Harl::*func[4])(void);
	public:
		void	complain(std::string);
		Harl();
		~Harl();
};

#endif