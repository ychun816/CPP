#ifndef ABC_HPP
#define ABC_HPP

#include "Base.hpp"
#include <iostream>

// Derived classes A/B/C (inherit frm Base)
class A : public Base
{
    public:
        A();
        ~A();
};

class B : public Base
{
    public:
        B();
        ~B();
};

class C : public Base
{
    public:
        C();
        ~C();
};

#endif