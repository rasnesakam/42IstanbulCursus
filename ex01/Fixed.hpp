#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	private:
		int number;
		static int bits;
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
};

std::ostream &operator << (std::ostream &out, const Fixed &c);


#endif