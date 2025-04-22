#include "Base.hpp"
#include "ABC.hpp"

int main()
{
    Base* p1 = Base::generate();
    Base* p2 = Base::generate();
    Base* p3 = Base::generate();

    std::cout << "Identifying using pointer:" << std::endl;
    Base::identify(p1);
    Base::identify(p2);
    Base::identify(p3);

    std::cout << "\nIdentifying using reference:" << std::endl;
    Base::identify(*p1);
    Base::identify(*p2);
    Base::identify(*p3);

    //cleanup
    delete p1;
    delete p2;
    delete p3;

    return 0;
}