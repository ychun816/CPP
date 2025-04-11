#include "Character.hpp"
#include <vector>

////constructor & destructor
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
//AMateria type can access func-'clone()'
Character::Character(const Character& src) :ICharacter(src), _name(src._name) 
{
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    std::cout << "Character " << _name << " copy constructor called" << std::endl;
}

//deep copy
//cleanup before assign!!!
Character& Character::operator=(const Character& src)
{
    if (this != &src)
    {
        this->_name = src._name;

        //cleanup, set to NULL!
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            // _inventory[i] = NULL;
        }
        
        //assign
        for (int i = 0; i < 4; i++)
        {
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
        }
    }
    std::cout << "Character " << _name << " assignment operator called" << std::endl;
    return (*this);
}

//delete inventory!!!
Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i];
        // _inventory[i] = NULL;
    }
    // clearTrash(); // EXTRA cleanup unequipped Materia
    std::cout << "Character default destructor called" << std::endl;
}


////getter
std::string const& Character::getName() const{ return (_name); }


////member funcs
//Character references it -> to be equipped 
void Character::equip(AMateria* m)
{
    if (!m)
        return ;

    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            // _inventory[i] = m->clone(); // Make a copy
            // delete m; // Delete the original to prevent memory leak
            std::cout << "Equip " << m->getType() << " to " << _name << std::endl;
            return ;
        }
    }
    std::cout << "❌Inventory full! Cannot equip more than 4 materias" << std::endl;
    delete m; // Delete the materia if it couldn't be equipped
}

//unequip()
//set NULL, not delete -> remove the pointer from the inventory
//analogy: the character dropping the Materia on the ground — it still exists, but character not holding it
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        std::cout << "Unequip " << _inventory[idx]->getType() << " from " << _name << std::endl;
        delete _inventory[idx]; // risky!//TRYING
        _inventory[idx] = NULL;
    }
}

/*for cleanup vr*/
// void Character::unequip(int idx) 
// {
//     if (idx >= 0 && idx < 4 && _inventory[idx]) 
//     {
//         if (_trashCount < 100) {
//             _trash[_trashCount++] = _inventory[idx]; // Save for cleanup
//         } else {
//             std::cout << "⚠️ Trash is full! Deleting directly." << std::endl;
//             delete _inventory[idx];
//         }
//         _inventory[idx] = NULL;
//     }
// }



void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
    else
        std::cout << "❌Cannot use: invalid slot or no materia equipped" << std::endl;
}


/*for cleanup unequip*/
// Character::Character() : _trashCount(0) 
// {
//     for (int i = 0; i < 4; ++i)
//         _inventory[i] = NULL;

//     for (int i = 0; i < 100; ++i)
//         _trash[i] = NULL;
// }


// void Character::clearTrash() 
// {
//     for (int i = 0; i < _trashCount; ++i) 
//     {
//         if (_trash[i])
//             delete _trash[i];
//     }
//     _trashCount = 0;
// }