#include "Nest.hpp"

//OUTER
Outer::Outer(){};
Outer::~Outer(){};

void Outer::accessInner()
{
    std::cout << "I'm using outer.accessinner!" << std::endl;
    Inner inner;
    inner.display();
}

//INNER
Outer::Inner::Inner(){};
Outer::Inner::~Inner(){};
void Outer::Inner::display()
{
    std::cout << "HEYYY I entered the inner class yo!" << std::endl;
}


int main()
{
    Outer outer;
    Outer::Inner inner;
    outer.accessInner();
    std::cout << "-----------" << std::endl;
    inner.display();
    return 0;
}