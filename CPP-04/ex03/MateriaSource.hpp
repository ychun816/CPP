#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"


//Derived concrete class (inherit frm Interface-IMateriaSource)
class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _prototypes[4];
   
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource& operator=(const MateriaSource& src);
        virtual ~MateriaSource();

        ////member funcs
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const& type);
    
};


#endif 