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
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;

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
    std::cout << "\n===== Wrong Animals =====" << std::endl;
    std::cout << "-------- constructors --------" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal(); 
    const WrongAnimal* wrongCat = new WrongCat();
    // const WrongAnimal* error = new Cat(); //not compilable
    std::cout << wrongCat->getType() << " " << std::endl;
    // std::cout << error->getType() << " " << std::endl; //not compilable
    
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