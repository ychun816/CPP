#include "Brain.hpp"

//constructor & destructor
//init ideas to empty string
Brain::Brain()
{
    std::cout << "Default Brain is created" << std::endl;
    for (int i = 0; i < MAX_IDEAS; i++)
        ideas[i] = "BUTTERFLIES~~🦋";
}

Brain::Brain(std::string idea)
{
    for (int i = 0; i < MAX_IDEAS; i++)
        ideas[i] = idea;
    std::cout << "Brain is created with idea: " << ideas[0] << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < MAX_IDEAS; i++)
        ideas[i] = other.ideas[i];
    std::cout << "Brain with ideas is copied" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < MAX_IDEAS; i++)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain with ideas is assigned" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain is destroyed" << std::endl;
}

//member funcs
std::string Brain::getIdea(int index) const
{
    return ((index >= 0 && index < 100) ? ideas[index] : "Invalid index (Range: 0 - 99)\n");
}


/* EXTRA*/
void Brain::setIdea(int index, const std:: string& idea)
{
    int i = 0;
    if (index >= 0 && index < MAX_IDEAS)
    {
        ideas[i] = idea;
        std::cout << "🧠 Idea [ " << index << " ] is set: " << idea << std::endl;
    }
    else
        std::cerr << "❌ Failed to set idea: Invalid index " << index << " (valid range: 0–" << MAX_IDEAS - 1 << ")\n";
}


/** NOTES
NOT recommended: *this = other;
*this = other;
-> invokes the assignment operator (operator=) inside the copy constructor
-> copy constructor's job is to directly initialize the object, whereas the assignment operator is used to copy values after an object is already initialized.
-> The assignment operator typically assumes that an object is already fully constructed. Using it in a copy constructor can lead to unnecessary operations. 

@note Directly copy the ideas array inside the copy constructor:
✅ Each element of ideas is copied directly.
✅ No extra function calls or unnecessary operations occur.
✅ The copy constructor does exactly what it's intended to do: initialize the object using another instance.

 */