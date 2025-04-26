#include "MutantStack.hpp"
#include <list>

int main()
{
    ////test MutantStack
    std::cout << "=== MutantStack ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17); // (top at the left): [17 - 5]
    std::cout << "Top element: " << mstack.top() << std::endl; //17
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; //1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    std::cout << "\nElements in MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();//5
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;//still points to the first element (5)
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);


    std::cout << "\n 𓇼 ⋆.˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ⋆.˚ 𓆉 " << std::endl;

    ////compare with std::list
    std::cout << "\n=== list containter ===" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << "Back element: " << l.back() << std::endl;//17

    l.pop_back();
    std::cout << "Size after pop: " << l.size() << std::endl;//1

    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);//[5, 3, 5, 737, 0] (bottom to top)

    std::cout << "\nElements in list:" << std::endl;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        std::cout << *it << std::endl;


    return 0;
}

/* NOTES:

////std::stack
//std::stack behavior itself (push/pop) is still Last-In-First-Out (LIFO).
//std::deque stores elements in insertion order

//.top() : returns the top element (last pushed)
//.pop()  : Remove from the back (top of stack)
//.begin() / .end() (iterator) : Walks from the front to back (earliest pushed to latest pushed)
//.push() : Add to the BACK of the underlying container (deque) / (= the TOP of the stack)

EX: push numbers 5, then 10, then 15
Top of stack --> [15] (=BACK  of deque)
                 [10]
Bottom       -->  [5] (=FRONT of deque)

======================================================

////std::list
//.push_back() : 
- Adds element to the end of the linked list
- like adding new train cars to the back of a train

EX: Head --> [5] -> [10] -> [15] -> NULL

//.pop_back() : removes the last element

*/