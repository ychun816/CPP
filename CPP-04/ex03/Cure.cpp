#include "Cure.hpp"

//constructor & destructor
Cure::Cure() : AMateria()
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const& src) : AMateria(src)
{
    this->_type = src._type;
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(Cure const& src)
{
    if (this != &src)
    {
        AMateria::operator=(src);
        this->_type = src._type;
    }
    std::cout << "Cure assign operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Ice destructor called" << std::endl;
}

//member funcs
//clone
AMateria* Cure::clone() const
{
    return new Cure(*this);
}

//use
//calls the getName() function of the ICharacter interface
void Cure::use(ICharacter& target)
{
    std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
    AMateria::use(target);
}