#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	private:
		int number;
		static const int bits;
	public:
		Fixed();
		~Fixed();
		Fixed(int number);
		Fixed(float number);
		int toInt(void) const;
		Fixed(const Fixed &fixed);
		float toFloat(void) const;
		void setRawBits(int number);
		int getRawBits( void ) const;
		Fixed& operator=(const Fixed& fixed);
		friend std::ostream &operator << (std::ostream &out, const Fixed &c);
};

// Arithmetic operators
Fixed &operator+(Fixed& lhs, const Fixed& rhs);
Fixed &operator-(Fixed& lhs, const Fixed& rhs);
Fixed &operator*(Fixed& lhs, const Fixed& rhs);
Fixed &operator/(Fixed& lhs, const Fixed& rhs);

// Increment overloads
Fixed& operator++(const Fixed& fixed);
Fixed operator++(const Fixed& fixed,int);
Fixed& operator--(const Fixed& fixed);
Fixed operator--(const Fixed& fixed,int);

// Conditional operators
inline bool operator>(const Fixed& lhs, const Fixed& rhs);
inline bool operator>=(const Fixed& lhs, const Fixed& rhs);
inline bool operator<(const Fixed& lhs, const Fixed& rhs);
inline bool operator<=(const Fixed& lhs, const Fixed& rhs);
inline bool operator==(const Fixed& lhs, const Fixed& rhs);
inline bool operator!=(const Fixed& lhs, const Fixed& rhs);

#endif