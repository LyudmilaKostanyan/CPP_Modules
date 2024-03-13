#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					val;
		static const int	frac = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int);
		Fixed(const float);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		static Fixed		&min(Fixed &num1, Fixed &num2);
		static const Fixed	&min(const Fixed &num1, const Fixed &num2);
		static Fixed		&max(Fixed &num1, Fixed &num2);
		static const Fixed	&max(const Fixed &num1, const Fixed &num2);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif