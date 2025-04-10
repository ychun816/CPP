#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#pragma once
#include "ICharacter.hpp"

#include <iostream>

/*
    AMateria (abstract)
      /        \
    Ice         Cure


    ICharacter (interface)
           |
    Character (concrete)


    IMateriaSource (interface)
           |
    MateriaSource (concrete)
*/


//abstract class
//abstract class, pure virtual func cannot be instantiated
class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const& src);
        AMateria& operator=(AMateria const& src);
        virtual ~AMateria();

        //getter
        std::string const& getType() const;
        
        //member funcs
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif