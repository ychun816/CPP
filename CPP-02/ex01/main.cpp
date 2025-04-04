#include "Fixed.hpp"

int main( void )
{
    std::cout << "------------- [Default] ------------\n" << std::endl;
    Fixed a;//defaut
    std::cout << std::endl;

    std::cout << "--------------- [Int] --------------\n" << std::endl;
    Fixed const b( 10 );//int constructor
    std::cout << std::endl;


    std::cout << "-------------- [Float] -------------\n" << std::endl;
    Fixed const c( 42.42f );//float constructor
    std::cout << std::endl;


    std::cout << "--------------- [Copy] --------------\n" << std::endl;
    Fixed const d( b );
    std::cout << std::endl;


    std::cout << "------------- [Assign] -------------\n" << std::endl;
    a = Fixed( 1234.4321f );
    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << std::endl;

    std::cout << "------------------------------------" << std::endl;
    return 0;
}

/* OUTPUT:
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called

a is 1234.43
b is 10
c is 42.4219
d is 10

a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer

Destructor called
Destructor called
Destructor called
Destructor called
$>
*/