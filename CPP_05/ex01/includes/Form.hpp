#ifndef FORM_HPP
# define FORM_HPP

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
		Form(const Form &other);
		Form		&operator=(const Form &other);
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignedGrade() const;
		int			getExecGrade() const;
		void		setIsSigned(bool isSigned);
}

#endif