#include "Cure.hpp"

////constructor & destructor
Cure::Cure() : AMateria("cure")
{
    std::cout << "🌈Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const& src) : AMateria(src)
{
    this->_type = src._type;
    std::cout << "🌈Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(Cure const& src)
{
    if (this != &src)
    {
        AMateria::operator=(src);
        this->_type = src._type;
    }
    std::cout << "🌈Cure assign operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "🌈Cure destructor called" << std::endl;
}

////member funcs
//clone (deep copy)
AMateria* Cure::clone() const
{
    return new Cure(*this);
}

//use
void Cure::use(ICharacter& target)
{
    std::cout << "* 🌈heals bob's wounds🌈 *" << std::endl;
    AMateria::use(target);
}