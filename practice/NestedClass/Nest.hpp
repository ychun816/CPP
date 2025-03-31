#ifndef NEST_HPP    
# define NEST_HPP

#include <iostream>

class Outer
{
    public:
        Outer();
        ~Outer();

        void accessInner();

    // private:
        class Inner
        {
            public:
                Inner();
                ~Inner();
                void display();
        };
};


#endif 