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
		void setRawBits(int const number);
		int getRawBits( void ) const;
		Fixed& operator=(const Fixed& fixed);

		// Static methods
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		// Arithmetic operators
		Fixed operator+(const Fixed& rhs);
		Fixed operator-(const Fixed& rhs);
		Fixed operator*(const Fixed& rhs);
		Fixed operator/(const Fixed& rhs);

		// Increment overloads
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		// Conditional operators
		inline bool operator> (const Fixed& rhs) const;
		inline bool operator>=(const Fixed& rhs) const;
		inline bool operator< (const Fixed& rhs) const;
		inline bool operator<=(const Fixed& rhs) const;
		inline bool operator==(const Fixed& rhs) const;
		inline bool operator!=(const Fixed& rhs) const;

};

std::ostream &operator<<(std::ostream &out, Fixed fixed);


#endif