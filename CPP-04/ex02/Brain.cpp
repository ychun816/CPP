#include "Brain.hpp"

Brain::Brain()//default
{
    std::cout << "Brain is created" << std::endl;
}

//NOT recommended: *this = other;
//*this = other;
//-> invokes the assignment operator (operator=) inside the copy constructor
//-> copy constructor's job is to directly initialize the object, whereas the assignment operator is used to copy values after an object is already initialized.
//-> The assignment operator typically assumes that an object is already fully constructed. Using it in a copy constructor can lead to unnecessary operations. 

//@note Directly copy the ideas array inside the copy constructor:
//✅ Each element of ideas is copied directly.
//✅ No extra function calls or unnecessary operations occur.
//✅ The copy constructor does exactly what it's intended to do: initialize the object using another instance.
Brain::Brain(const Brain& other)//copy
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    std::cout << "Brain is copied" << std::endl;
}

Brain& Brain::operator=(const Brain& other)//assign
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()//decons
{
    std::cout << "Brain is destroyed" << std::endl;
}

void Brain::setIdea(int index, const std:: string& idea)
{
    int i = 0;
    if (index >= 0 && index < 100)
    {
        ideas[i] = idea;
    }
    std::cout << "🧠 Idea [ " << index << " ] is set: " << idea << std::endl;
}

std::string Brain::getIdea(int index) const
{
    return ((index >= 0 && index < 100) ? ideas[index] : "Invalid index (Range: 0 - 99)\n");
}

/* NOTES ON COPY CONSTRUCT
❓ When Is *this = other; OK?

There are cases where calling operator= in the copy constructor might be acceptable:

If your class only has simple built-in types (like int, double).
If the assignment operator does nothing except copy values without touching dynamically allocated memory.
However, in general, it's a bad practice in C++ to use operator= inside the copy constructor.
*/