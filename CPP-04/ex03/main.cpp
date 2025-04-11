#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << "========== [ Set Materia ] ==========" << std::endl;
    std::cout << "----------- [Create MateriaSource] --------------" << std::endl;
    IMateriaSource* src = new MateriaSource();
    
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n========== [ Set Character A ] ==========" << std::endl;
    std::cout << "----------- [Character : ME] --------------" << std::endl;
    ICharacter* me = new Character("ME");
    // Equip materias to the character (me)
    std::cout << "\n========== [ TEST equip() ] ==========" << std::endl;
    std::cout << "----------- [Equip on Character ME] --------------" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");//5th should fail!
    me->equip(tmp);

    std::cout << "----------- [Unequip on Character ME] --------------" << std::endl;
    me->unequip(0);

    tmp = src->createMateria("cure");//equip after unequip -> should work!
    me->equip(tmp);


    std::cout << "\n========== [ Set Character B ] ==========" << std::endl;
    std::cout << "----------- [Character : BOB] --------------" << std::endl;
    ICharacter* bob = new Character("BOB");
    
    std::cout << "\n========== [ TEST use() ] ==========" << std::endl;
    me->use(0, *bob);//cure
    me->use(4, *bob);//ice

    std::cout << "\n========== [ Cleanup ] ==========" << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}