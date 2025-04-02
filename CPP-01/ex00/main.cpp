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

    //zombie in stack -> destroyed automatically
    std::cout << "===== Stack Zombie =====" << std::endl;
    // Zombie zb_stack;
    randomChump(input_name);//Zombie zb_stack -> auto destroyed
    std::cout << std::endl;

    //zombie in heap -> allocate & destroy manually
    std::cout << "===== Heap Zombie =====" << std::endl;
    Zombie *zb_heap;
    zb_heap = newZombie(input_name);
    zb_heap->announce();
    delete  zb_heap;
    std::cout << std::endl;

    return (0);
}