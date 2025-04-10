#include "AMateria.hpp"

////constructor & destructor
AMateria::AMateria() : _type("default")
{
    std::cout << "🥛AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "🥛AMateria " << _type << " called" << std::endl;
}

AMateria::AMateria(AMateria const& src) : _type(src._type)
{
    std::cout << "🥛AMateria " << _type << " copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const& src)
{
    if (this != &src)
        this->_type = src._type;
    std::cout << "🥛AMateria " << _type << " copy assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "🥛AMateria destructor called" << std::endl;
}

////getter
std::string const& AMateria::getType() const { return (this->_type);}
        
////member funcs
//clone (Pure virtural func) -> no need implement in base abstract class

//use (virtural func) -> need implement in base abstract class / derived class
void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "🥛AMateria use function" << std::endl;
}