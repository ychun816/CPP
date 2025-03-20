#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;//Call default constructor (a is initialized to 0)
    Fixed b( a );//Call copy constructor
    Fixed c;//Call the default constructor (c is initialized to 0)

    c = b;//Call the copy assignment operator (assigns b's value to c)

    std::cout << a.getRawBits() << std::endl;//Call getRawBits(), which prints 0 since all values are 0
    std::cout << b.getRawBits() << std::endl;////🤡CHECK THIS PROB??-1153875768
    std::cout << c.getRawBits() << std::endl;

    return 0;
}

/* expected output:

$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>

*/