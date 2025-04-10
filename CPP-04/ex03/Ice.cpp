#include "Ice.hpp"

////constructor & destructor
Ice::Ice() : AMateria("ice")
{
    std::cout << "🧊Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const& src) : AMateria(src)
{
    this->_type = src._type;
    std::cout << "🧊Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(Ice const& src)
{
    if (this != &src)
    {
        AMateria::operator=(src);
        this->_type = src._type;
    }
    std::cout << "🧊Ice assign operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "🧊Ice destructor called" << std::endl;
}

////member funcs
/** CLONE (deep copy)
 * return a new copy of the same class (Ice)
 * enable polymorphic duplication of Ice when working with AMateria*
*/
AMateria* Ice::clone() const
{
    return new Ice(*this);
}

//use
//calls the getName() function of the ICharacter interface
void Ice::use(ICharacter& target)
{
    std::cout << "* 🧊shoots an ice bolt at " << target.getName() << " 🧊*" << std::endl;
    AMateria::use(target);
}
