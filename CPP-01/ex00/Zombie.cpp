#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "default Zombie is created (Constructor)" << std::endl;//created
}

Zombie::~Zombie()
{
    if (!_name.empty())
        std::cout << _name << " Zombie is destroyed (Destructor)" << std::endl;//destroyed
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

