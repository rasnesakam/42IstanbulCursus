#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

	private:
		int number;
		static int bits;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed &fixed);
		Fixed& operator=(Fixed &fixed);
		void setRawBits(int rawBits);
		int getRawBits( void ) const;
};

#endif