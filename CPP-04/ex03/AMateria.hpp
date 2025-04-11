#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#pragma once
#include "ICharacter.hpp"

#include <iostream>

//base abstract class
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
        virtual ~AMateria();//destructor made virtual to be overridden

        ////getter
        std::string const& getType() const;
        
        ////member funcs
        virtual AMateria* clone() const = 0;//pure virtual func
        virtual void use(ICharacter& target);//virtual func
};

#endif

/* WHOLE STRUCTOR NOTE

 
       AMateria         (Base Abstract Class)
      /        \
    Ice         Cure    (Derived Concrete Class)


//In Base Abstract Class (AMateria):
virtual ~AMateria();
virtual AMateria* clone() const = 0;//pure virtual func
virtual void use(ICharacter& target);//virtual func

//In Derived Concrete Class (Ice, Cure):
AMateria* Cure::clone() const -> deep copy whole class (new Cure(*this))
void Cure::use(ICharacter& target) -> need to implement

****************************************************************************

    ICharacter            (Interface)
        |
    Character             (Concrete class)

//In Ineterface (ICharacter):
No variable / All is pure virtual func

//In Concrete Class (Character):
!! NEED TO IMPLEMENT ALL PURE VIRTUAL FUNC !!
void equip(AMateria* m);
void unequip(int idx);
void use(int idx, ICharacter& target);


****************************************************************************

    IMateriaSource        (Interface)
          |
    MateriaSource         (Concrete class)


~~~SAME LOGIC AS ICharacter

*/