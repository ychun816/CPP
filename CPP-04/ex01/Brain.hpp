#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define MAX_IDEAS 100

/* IMPORTANT NOTIONS:
Deep Copy vs. Shallow Copy
SHALLOW COPY: Just copies the pointer, leading to multiple objects pointing to the same memory.
DEEP COPY: Ensures each Dog or Cat gets its own copy of the Brain.
*/
class Brain
{
    protected://change to protected
        std::string ideas[MAX_IDEAS];

    public:
        Brain();
        Brain(std::string idea);//constructor with string
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        //member funcs
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

# endif