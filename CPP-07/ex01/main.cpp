#include "Iter.hpp"

int main()
{
    std::cout << "=== Test print int ===" << std::endl;
    int nbs[] = {1, 2, 3};

    // Explicitly instantiate print<int> for use with iter
    // in C++98 need to specify it -> This is not necessary in C++11 and later, as templates are instantiated automatically
    iter(nbs, 3, print<int>);

    std::cout << "\n=== Test print float ===" << std::endl;
    float floats[] = {1.1f, 2.2f, 3.3f, 42.4f};
    iter(floats, 4, print<float>);

    std::cout << "\n=== Test check even (int) ===" << std::endl;
    int nbs2[] = {1, 2, 3, 4};
    iter(nbs2, 4, checkEven<int>);

    std::cout << "\n=== Test multiplyTWO (int) ===" << std::endl;
    int nbs3[] = {1, 2, 3, 4, 100};
    iter(nbs3, 5, multiplyTWO<int>);

    //std::cout << "\n=== Test multiply(int) ===" << std::endl;

    return 0;
}