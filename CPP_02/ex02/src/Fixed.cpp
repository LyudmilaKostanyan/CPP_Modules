#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	setRawBits(0);
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed() {}

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
	setRawBits(num * (1 << frac));
}

Fixed::Fixed(const float num)
{
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

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	setRawBits(getRawBits() + 1);
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	setRawBits(getRawBits() - 1);
	return (tmp);
}

Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	return (num1 > num2 ? num2 : num1);
}

const Fixed	&Fixed::min(const Fixed &num1, const Fixed &num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num2 : num1);
}

Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	return (num1 > num2 ? num1 : num2);
}

const Fixed	&Fixed::max(const Fixed &num1, const Fixed &num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}