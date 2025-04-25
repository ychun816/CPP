#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 10;

    std::cout << "=== CREATE INT ===" << std::endl;
    std::cout << "a: " << a << " | b: " << b << std::endl;

    std::cout << "\n⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖" << std::endl;
    std::cout << "=== TEST SWAP ===" << std::endl;
    std::cout << "-- Before swap --" << std::endl; 
    std::cout << "a = " << a << " | b = " << b << std::endl;
    swap(a, b);
    std::cout << std::endl;
    std::cout << "-- After swap --" << std::endl;
    std::cout << "a = " << a << " | b = " << b << std::endl;

    std::cout << "\n⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖" << std::endl;
    std::cout << "=== TEST MIN ===" << std::endl;
    std::cout << "Min: " << min(a, b) << std::endl;

    std::cout << "\n⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖" << std::endl;
    std::cout << "=== TEST MAX ===" << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;
}