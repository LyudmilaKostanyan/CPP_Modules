#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (val);
}

void	Fixed::setRawBits(int const raw)
{
	this->val = raw;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num * (1 << frac));
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(num * (1 << frac)));
}

float	Fixed::toFloat() const
{
	return ((float)getRawBits() / (1 << frac));
}

int		Fixed::toInt() const
{
	return (getRawBits() / (1 << frac));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}