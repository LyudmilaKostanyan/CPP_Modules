#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		std::string	getName() const;
		int			getGrade() const;
		void		setName(std::string name);
		void		setGrade(int grade);
		void		increment();
		void		decrement();
		void		signForm(Form &form);
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif 