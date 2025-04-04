#include "Fixed.hpp"

int	main(void) 
{
	std::cout << "------ Constructor & Copy ------" << std::endl;
	Fixed	a;
	Fixed	b(5);
	Fixed	c(5.5f);
	Fixed	d(c);

	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D copy of B: " << d << std::endl;
	std::cout << std::endl;

	std::cout << "------ Assignment operator ------" << std::endl;
	a = Fixed(10.1f);
	std::cout << "A after assignment: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "------ Arithmetic operator ------" << std::endl;
	std::cout << "A + B = " << a + b << std::endl;
	std::cout << "A - B = " << a - b << std::endl;
	std::cout << "A * B = " << a * b << std::endl;
	std::cout << "A / B = " << a / b << std::endl;
	std::cout << std::endl;

	std::cout << "------ Comparison operator ------ " << std::endl;
	std::cout << "A > B : " << (a > b) << std::endl;
	std::cout << "A < B : " << (a < b) << std::endl;
	std::cout << "A >= B: " << (a >= b) << std::endl;
	std::cout << "A <= B: " << (a <= b) << std::endl;
	std::cout << "A == B: " << (a == b) << std::endl;
	std::cout << "A != B: " << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << "------ Pre-Increment/Decrement operator ------" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A pre-increment: " << ++a << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A pre-decrement: " << --a << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "------ Post-Increment/Decrement operator ------" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A post-increment: " << a++ << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "A post-decrement: " << a-- << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "------ Min/Max operator ------" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "Min between A and B: " << Fixed::min(a, b) << std::endl;
	std::cout << "Max between A and B: " << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "------ Const Min/Max operator ------" << std::endl;
	const Fixed	e(3.14f);
	const Fixed	f(6.28f);
	std::cout << "E: " << e << std::endl;
	std::cout << "F: " << f << std::endl;
	std::cout << "Min between E and F: " << Fixed::min(e, f) << std::endl;
	std::cout << "Max between E and F: " << Fixed::max(e, f) << std::endl;
	std::cout << std::endl;
	return 0;
}


/** main short vr.

int main( void ) 
{ 
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0; 
}

OUTPUT:
$> ./a.out 0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>

*/