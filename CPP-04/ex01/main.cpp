#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define COUNT 4

int main() 
{
    //Create array of Animals
    std::cout << "\n========== Create Animals ==========" << std::endl;
    const Animal* animals[COUNT];

    for (unsigned int i = 0; i < COUNT; i++)
    {
        if (i < COUNT / 2)
        {
            std::cout << "[ " << i + 1 << " ] ";
            animals[i] = new Dog();
        }

        else
        {
            std::cout << "[ " << i + 1 << " ] ";
            animals[i] = new Cat();
        }
    }

    //create Dog & set ideas
    std::cout << "\n======== Set & Print Dog Idea (Deep Copy) ========" << std::endl;
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "🦴 ME WANT A BONE! 🦴");
    std::cout << "Dog1 Idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;

    //copy Dog1 to Dog2_cp
    std::cout << "\n======== Test Copy Constructor ========" << std::endl;
    Dog dog2_cp(*dog1);
    std::cout << "Dog2_cp (copied) Idea[0]: " << dog2_cp.getBrain()->getIdea(0) << std::endl;

    //assign Dog2_cp to Dog3 & //create Dog3 & set idea
    std::cout << "\n======== Test Assignment Operator ========" << std::endl;
    Dog dog3;
    dog3.getBrain()->setIdea(0, "💤 VAMIR A MIMI! 💤");
    std::cout << "Dog3 Original Idea[0]: " << dog3.getBrain()->getIdea(0) << std::endl;

    dog3 = dog2_cp;//assign dog2_cp to dog3
    std::cout << "Dog3 After Assignment Idea[0]: " << dog3.getBrain()->getIdea(0) << std::endl;

    //delete animals
	std::cout << "\n========== Cleanup ==========" << std::endl;
    for (unsigned int i = 0; i < 4; i++)
    {
        std::cout << "[ " << i + 1 << " ] ";
        delete animals[i];
        std::cout << std::endl;
    }
    delete dog1;


    return 0; 
}
