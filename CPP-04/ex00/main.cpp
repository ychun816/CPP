// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
// #include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    //animals test
    std::cout << "========== Animals ==========" << std::endl;
    std::cout << "-------- constructors --------" << std::endl;
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    //make sound
    std::cout << "-------- make sounds --------" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    // Cleanup
    std::cout << "-------- cleanup --------" << std::endl;
    delete meta;
    delete j;
    delete i;

    //Wrong animal
    //Wrong Cat
    std::cout << "\n===== Wrong Animals =====" << std::endl;
    std::cout << "-------- constructors --------" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal(); 
    const WrongAnimal* wrongCat = new WrongCat();
    // const WrongAnimal* error = new Cat();
    std::cout << wrongCat->getType() << " " << std::endl;
    // std::cout << error->getType() << " " << std::endl;
    
    //make sound
    std::cout << "-------- make sounds --------" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound(); //will output the cat sound!
    // error->makeSound();

    // Cleanup
    std::cout << "-------- cleanup --------" << std::endl;
    delete wrongAnimal;
    delete wrongCat;

    return 0; 
}