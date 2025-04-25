#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 10;

    std::cout << "=== CREATE INT ===" << std::endl;
    std::cout << "a: " << a << " | b: " << b << std::endl;

    std::cout << "\n\n⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖" << std::endl;
    std::cout << "=== SWAP ===" << std::endl;
    std::cout << "-- Before swap --" << std::endl; 
    std::cout << "a = " << a << " | b = " << b << std::endl;
    swap(a, b);
    std::cout << std::endl;
    std::cout << "-- After swap --" << std::endl;
    std::cout << "a = " << a << " | b = " << b << std::endl;

    std::cout << "\n\n⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖" << std::endl;
    std::cout << "=== MIN / MAX ===" << std::endl;
    std::cout << "Min: " << min(a, b) << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;
}

/* SUBJECT
int main( void ) 
{
    int a = 2;
    int b = 3;
    
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}
*/