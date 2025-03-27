#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

/* IMPORTANT NOTIONS:
Deep Copy vs. Shallow Copy
SHALLOW COPY: Just copies the pointer, leading to multiple objects pointing to the same memory.
DEEP COPY: Ensures each Dog or Cat gets its own copy of the Brain.
*/

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();//default
        Brain(const Brain& other);//copy
        Brain& operator=(const Brain& other);//assign
        ~Brain();//decons

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

# endif