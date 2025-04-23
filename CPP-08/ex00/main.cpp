#include "easyfind.hpp"

int main()
{
    try
    {
        //test with vec container
        std::cout << "=== TEST VEC CONTAINER ===" << std::endl;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Found it~! 💘 int value: " << *it << std::endl;
        std::cout << std::endl;

        //test with char container
        std::cout << "=== TEST LIST CONTAINER ===" << std::endl;
        std::list<int> list;
        list.push_back(30);
        list.push_back(50);
        list.push_back(20);
        std::list<int>::iterator listIT = easyfind(list, 50);
        std::cout << "🧧Found!!! int value: " << *listIT << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}