#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signedGrade;
		const int			execGrade;
	public:
		Form();
		~Form();
		Form(std::string name, const int &signedGrade, const int &execGrade);
		Form(const Form &other);
		Form		&operator=(const Form &other);
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
		bool		getIsSigned() const;
		int			getSignedGrade() const;
		int			getExecGrade() const;
		void		setIsSigned(bool isSigned);
		void		beSigned(Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif