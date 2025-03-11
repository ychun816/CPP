#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    if (!_name.empty())
        std::cout << _name << " Zombie is Destryoed!" << std::endl;//destroyed
}

//setname
void    Zombie::setName(std::string name)
{
    _name = name;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
