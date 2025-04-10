#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

//he blueprint library for creating new Materias
//store up to 4 learned materia templates
class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _prototypes[4];
   
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource& operator=(const MateriaSource& src);
        virtual ~MateriaSource();

        //member funcs
        // interface implementations
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const& type);
    
};


#endif 