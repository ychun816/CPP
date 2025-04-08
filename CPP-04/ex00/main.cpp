#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    std::cout << "========== Animals ==========" << std::endl;
    std::cout << "-------- constructors --------" << std::endl;
    const Animal* animal = new Animal(); 
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    // std::cout << dog->getType() << " " << std::endl;
    // std::cout << cat->getType() << " " << std::endl;

    //print types
    std::cout << "\n-------- print types --------" << std::endl;
    std::cout << "Animal type: " << animal->getType() << " " << std::endl;
    std::cout << "Dog type: " << dog->getType() << " " << std::endl;
    std::cout << "Cat type: " << cat->getType() << " " << std::endl;

    //make sound
    std::cout << "\n-------- make sounds --------" << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();

    // Cleanup
    std::cout << "\n-------- cleanup --------" << std::endl;
    delete animal;
    delete dog;
    delete cat;

    //Wrong animal
    //Wrong Cat
    std::cout << "\n\n===== Wrong Animals =====" << std::endl;
    std::cout << "\n-------- constructors --------" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal(); 
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n-------- print type --------" << std::endl;
    std::cout << "Wrong Animal type: " <<  wrongAnimal->getType() << " " << std::endl;
    std::cout  << "Wrong Cat type: " << wrongCat->getType() << " " << std::endl;

    //wrong class inheritance -> cannot compile
    // const WrongAnimal* error = new Cat(); //not compilable
    // std::cout << error->getType() << " " << std::endl; //not compilable
    
    //make sound
    std::cout << "\n-------- make sounds --------" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound(); //will output the cat sound!
    // error->makeSound();

    // Cleanup
    std::cout << "\n-------- cleanup --------" << std::endl;
    delete wrongAnimal;
    delete wrongCat;

    return 0; 
}