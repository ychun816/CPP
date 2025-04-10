#include "MateriaSource.hpp"

//constructor & destructor
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _prototypes[i] = NULL;
    std::cout << "MateriaSource default constructor called" << std::endl;
}

//deep copy _prototypes
MateriaSource::MateriaSource(const MateriaSource& src) : IMateriaSource(src)
{
    //deep copy the _prototypes
    for (int i = 0; i < 4; i++)
    {
        if (src._prototypes[i])
            this->_prototypes[i] = src._prototypes[i]->clone();
        else
            this->_prototypes[i] = NULL;
    }

    for (int i = 0; i < 4; i++)
    {
        if (src._prototypes[i])
            this->_prototypes[i] = src._prototypes[i]->clone();
        else
            this->_prototypes[i] = NULL;
    }
    std::cout << "MateriaSource " << _prototypes << " copy constructor called" << std::endl;

}

//deep copy
//cleanup before assign!!!
MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
    //cleanup!! set to NULL!
   for (int i = 0; i < 4; i++)
   {
        delete _prototypes[i];
        _prototypes[i] = NULL;
    }

    //assign
    for (int i = 0; i < 4; i++)
    {
        if (src._prototypes[i])
            this->_prototypes[i] = src._prototypes[i]->clone();
    }
    std::cout << "MateriaSource " << _prototypes << " assign operator called" << std::endl;
    return (*this);
}

//delete prototypes!!!
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _prototypes[i];
    std::cout << "MateriaSource destructor called" << std::endl;
}


//member funcs
void MateriaSource::learnMateria(AMateria*)//subject has prob? 
{
    for (int i = 0; i < 4; i++)
    {
        // if (!m)
        //     return ;

        for (int i = 0; i < 4; i++)
        {
            if (_prototypes[i] == NULL)
            {
                _prototypes[i] = AMateria*;
                // _prototypes[i] = m;
                std::cout << "MateriaSource " << _prototypes[i]->getType() << " learned" << std::endl;
                break ;
            }
            else
                std::cout << "MateriaSource already full" << std::endl;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_prototypes[i] && _prototypes[i]->getType() == type)
        {
            std::cout << "MateriaSource " << _prototypes[i]->getType() << " created" << std::endl;
        }
        return (_prototypes[i]->clone());
    }
}