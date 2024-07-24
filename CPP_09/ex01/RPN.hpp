#ifndef RPH_HPP
# define RPH_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<double> nums;
	public:
		RPN();
		RPN(std::string arg);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
};

#endif