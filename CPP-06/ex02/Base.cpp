#include "Base.hpp"
#include "ABC.hpp"

//constructor & destructor
// Base::Base(){}
Base::~Base(){}

////member funcs
// generate() -> create random instances of A/B/C
//std::srand(std::time(nullptr)) -> seeds the random number generator using the current time
//std::rand() -> generates a random number
Base* Base::generate()
{
    std::srand(std::time(NULL)); // Seed the random number generator
    int randomNB = std::rand() % 3; // Generate a random number between 0 and 2
    if (randomNB == 0)
        return (new A());
    else if (randomNB == 1)
        return (new B());
    else
        return (new C());

}


void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

//Use references and catch exceptions.
void Base::identify(Base& p)
{
    try  
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        // (void)a; // Avoid unused variable warning
    }
    catch (std::bad_cast &e) {}
    
    try  
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        // (void)b; // Avoid unused variable warning
    }
    catch (std::bad_cast &e) {}

    try  
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        // (void)b; // Avoid unused variable warning
    }
    catch (std::bad_cast &e) {}
        
    //if all three dynamic_cast attempts fail -> fallback here:
    std::cout << "Unknown type" << std::endl;
}


/*

1. std::srand(std::time(nullptr));?
-> seeds the random number generator using the current time.
-> a seed as the "starting point" for generating a series of random numbers.

🔍 Why It’s Needed:
By default, if you use std::rand() without seeding, you get the same sequence of numbers every time you run the program.
std::srand() sets the starting state of the random number generator.
std::time(nullptr) returns the current system time (in seconds), ensuring the seed is different each time you run the program.

💡 Analogy:
Imagine random numbers are pages in a shuffled book.
Without srand(), you open the book at the same place every time.
With srand(time), you open the book at a different spot based on the current time.

*/