#include "Zombie.hpp"

/**
Stack-allocated zombies (like the one in your main function and in randomChump) are automatically destroyed when they go out of scope
Heap-allocated zombies (created with new in newZombie) must be manually destroyed with delete
*/



int main()
{
    std::string input_name;

    // Ask user for input
    std::cout << "Enter a name for your zombie: ";
    std::getline(std::cin, input_name);
    std::cout << std::endl;

    //zombie in stack -> manually allocate
    Zombie *zb_heap;
    //zombie in heap -> destroyed automatically
    Zombie zb_stack;


    // Heap zombie
    zb_heap = newZombie(input_name);
    zb_heap->announce();
    delete  zb_heap;

    std::cout << "--------------------------" << std::endl;

    // Stack zombie (auto destroyed) 
    randomChump(input_name);

}