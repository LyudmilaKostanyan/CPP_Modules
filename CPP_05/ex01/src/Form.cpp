Form::Form() {}

Form::~Form() {}

Form::Form(const Form &other) : name(other.name), signedGrade(other.signedGrade), execGrade(other.execGrade), isSigned(other.isSigned) {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getIsSigned() const
{
	return this->isSigned;
}

int	Form::getSignedGrade() const
{
	return this->signedGrade;
}

int	Form::getExecGrade() const
{
	return this->execGrade;
}

void	Form::setisSigned(bool isSigned)
{
	this->isSigned = isSigned;
}