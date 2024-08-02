#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		void		setIdeas(std::string *type);
		std::string	*getType() const;
		Brain		&operator=(const Brain &other);
};

#endif