#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

//derived/concrete class (inherit frm AMateria)
class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const& src);
        Ice& operator=(Ice const& src);
        ~Ice();

        //member funcs
        AMateria* clone() const;
        void use(ICharacter& target);
};


#endif