#include "Zombie.hpp"

int main()
{
    Zombie *newZombie;
    std::string input_name;

    std::getline(std::cin, input_name);

// Heap allocation (must delete manually)    
    newZombie = newZombie(input_name);
    annouce();
    Zombie();

// Stack allocation (auto destroyed) 
    randomChump(input_name);
    ~Zombie();
}