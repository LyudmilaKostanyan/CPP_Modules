#ifndef RPH_HPP
# define RPH_HPP

# include <iostream>
# include <queue>

class RPN
{
	private:
		std::queue<double> nums;
		std::queue<double> nums_b;
		std::queue<char> signs;
		std::queue<char> signs_b;
	public:
		RPN();
		RPN(std::string arg);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		bool	argument_hendler(std::string arg);
};

#endif