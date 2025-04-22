#include "whatever.hpp"


int main()
{
    int a = 2;
    int b = 10;

    std::cout << "=== CREATE INT ===" << std::endl;
    std::cout << "a: " << a << " | b: " << b << std::endl;

    std::cout << "\n=== TEST SWAP ===" << std::endl;
    std::cout << "-- Before swap --" << std::endl; 
    std::cout << "a = " << a << " | b = " << b << std::endl;
    swap(a, b);
    std::cout << std::endl;
    std::cout << "-- After swap --" << std::endl;
    std::cout << "a = " << a << " | b = " << b << std::endl;

    std::cout << "\n=== TEST MIN ===" << std::endl;
    std::cout << "Min: " << min(a, b) << std::endl;

    std::cout << "\n=== TEST MAX ===" << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;
}