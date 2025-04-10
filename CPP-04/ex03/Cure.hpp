#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

//derived/concrete class (inherit frm AMateria)
class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const& src);
        Cure& operator=(Cure const& src);
        ~Cure();

        //member funcs
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif