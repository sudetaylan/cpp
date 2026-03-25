#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
	private:
		int value;
		static const int bits;

	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &op);
		~Fixed();        
		bool operator>(Fixed const& obj);
		bool operator<(Fixed const& obj);
		bool operator<=(Fixed const& obj);
		bool operator>=(Fixed const& obj);
		bool operator==(Fixed const& obj);
		bool operator!=(Fixed const& obj);
		Fixed operator+(Fixed const& obj);
		Fixed operator-(Fixed const& obj);
		Fixed operator*(Fixed const& obj);
		Fixed operator/(Fixed const& obj);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& obj);

#endif