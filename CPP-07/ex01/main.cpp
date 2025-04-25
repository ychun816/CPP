#include "Iter.hpp"

// Explicitly instantiate print<int> for use with iter)
// in C++98 need to specify it -> This is not necessary in C++11 and later, as templates are instantiated automatically (with 'auto')

int main()
{
    std::cout << "=== Print int ===" << std::endl;
    int nbs[] = {1, 2, 3};

    iter(nbs, 3, print<int>);

    std::cout << "\n=== Print float ===" << std::endl;
    float floats[] = {1.1f, 2.2f, 3.3f, 42.4f};
    iter(floats, 4, print<float>);

    std::cout << "\n=== Check even (int) ===" << std::endl;
    int nbs2[] = {1, 2, 3, 4};
    iter(nbs2, 4, checkEven<int>);

    std::cout << "\n=== multiplyTWO (int) ===" << std::endl;
    int nbs3[] = {1, 2, 3, 4, 100};
    iter(nbs3, 5, multiplyTWO<int>);

    std::cout << "\n=== Multiply operator (int) ===" << std::endl;
    int nbs4[] = {1, 2, 3, 5, 7};
    iter(nbs4, 5, Multiply<int>(5));
    iter(nbs4, 5, print<int>);

    return 0;
}