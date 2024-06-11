#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signedGrade;
		const int			execGrade;
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, const int &signedGrade, const int &execGrade);
		AForm(const AForm &other);
		AForm		&operator=(const AForm &other);
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
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getSignedGrade() const;
		int				getExecGrade() const;
		void			setIsSigned(bool isSigned);
		virtual void	beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor);
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif