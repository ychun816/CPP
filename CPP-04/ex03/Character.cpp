#include "Character.hpp"

//constructor & destructor
Character::Character() : _name("default")
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) :  _name(name)
{   
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character " << _name << " called" << std::endl;
}

//deep copy the _inventory
Character::Character(const Character& src) : _name(src._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

//deep copy
//cleanup before assign!!!
Character& Character::operator=(const Character& src) : ICharacter(src)
{
    if (this != &src)
    {
        this->_name = src._name;

        //cleanup!! set to NULL!
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
        
        //assign
        for (int i = 0; i < 4; i++)
        {
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
        }
    }
    std::cout << "Character assignment operator called" << std::endl;
    return (*this);
}

//delete inventory!!!
Character::~Character()
{
    for (int i = 0; i < 4, i++)
        delete _inventory[i];
    std::cout << "Character default destructor called" << std::endl;
}

//getter
std::string const& Character::getName() const{ return (_name); }

//member funcs

//Character references it
void Character::equip(AMateria* m)
{
    if (!m)
        return ;

    for (int i = 0; i < 4, i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            break;//do i need?
        }
    }   
}

//set NULL, not delete -> remove the pointer from the inventory
// analogy: the character dropping the Materia on the ground — it still exists, but the character just isn't carrying it anymore.
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
         _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}
