#include "Cat.hpp"
#include "Dog.hpp"

int main() 
{
    //Create array of Animals: 2 dogs and 2 cats to check
    std::cout << "========== Create Animals ==========" << std::endl;
    const Animal* animals[4];
	animals[0] = new Dog();
	std::cout << std::endl;
    animals[1] = new Dog();
	std::cout << std::endl;
    animals[2] = new Cat();
	std::cout << std::endl;
    animals[3] = new Dog();
	std::cout << std::endl;

    //Deep Copy Test ->Dog brain
    //Creates a Dog dynamically.
    //set the first idea in the dog's Brain.
    std::cout << "========== Deep Copy test ==========" << std::endl;
    Dog *dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "Bite mama's shoes!!");
    std::cout << std::endl;

    //Copy Constructor Test
    //Copies dog1 into dog2 using the copy constructor.
    std::cout << "========== Copy Constructor test ==========" << std::endl;
    Dog dog2_cp(*dog1);
    std::cout << std::endl;

    //Assignment Operator Test
    //Creates a temporary Dog object dog3 (stack-allocated).
    //Sets an idea in dog3's brain: "Another idea".
    //Assigns dog3 = dog2; (this tests the operator= overload).
    //Prints dog3's idea again to verify if dog3 correctly copied dog2.
    std::cout << "========== Assignment Operator test ==========" << std::endl;
    Dog dog3;
    //->set idea in dog3
    dog3 = dog2;
    //print to check if correclty assigned 

    //cleanup
    //Deletes all dynamically allocated Animal objects.
    //delete dog1 in the end outside of loop -> avoid leak
    std::cout << "========== Cleanup ==========" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
    delete dog1;
    std::cout << std::endl;

    return 0; 
}


/*REF
int main() {
	const Animal* animals[4];

	// Creating half dogs and half cats
	animals[0] = new Dog();
	std::cout << std::endl;
	animals[1] = new Dog();
	std::cout << std::endl;
	animals[2] = new Cat();
	std::cout << std::endl;
	animals[3] = new Cat();
	std::cout << std::endl;

	// Setting and checking ideas
	Dog *dog1 = new Dog();
	std::cout << std::endl;
	dog1->getBrain()->setIdea(0, "Chase the mailman!");
	std::cout << std::endl;

	Dog dog2(*dog1);
	std::cout << std::endl;

	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
	{
	Dog dog3;
	dog3.getBrain()->setIdea(0, "Another idea");
	std::cout << "Dog3 Brain Idea[0]: " << dog3.getBrain()->getIdea(0) << std::endl;
	dog3 = dog2;
	std::cout << "Dog3 Brain Idea[0]: " << dog3.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;


	// Dog dog2 = *dog1;  // Test deep copy
	// std::cout << std::endl;

	std::cout << "Dog1 Brain Idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << "Dog2 Brain Idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	// Clean up
	for (int i = 0; i < 4; ++i) {
		delete animals[i];
		std::cout << std::endl;
	}
	delete dog1;
	std::cout << std::endl;

	return (0);
}
*/




// int main() 
// {
//     //animals test
//     std::cout << "========== Animals ==========" << std::endl;
//     std::cout << "-------- constructors --------" << std::endl;
//     const Animal* meta = new Animal(); 
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     //make sound
//     std::cout << "-------- make sounds --------" << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();

//     // Cleanup
//     std::cout << "-------- cleanup --------" << std::endl;
//     delete meta;
//     delete j;
//     delete i;

//     //Wrong animal
//     //Wrong Cat
//     std::cout << "\n===== Wrong Animals =====" << std::endl;
//     std::cout << "-------- constructors --------" << std::endl;
//     const WrongAnimal* wrongAnimal = new WrongAnimal(); 
//     const WrongAnimal* wrongCat = new WrongCat();
//     // const WrongAnimal* error = new Cat();
//     std::cout << wrongCat->getType() << " " << std::endl;
//     // std::cout << error->getType() << " " << std::endl;
    
//     //make sound
//     std::cout << "-------- make sounds --------" << std::endl;
//     wrongAnimal->makeSound();
//     wrongCat->makeSound(); //will output the cat sound!
//     // error->makeSound();

//     // Cleanup
//     std::cout << "-------- cleanup --------" << std::endl;
//     delete wrongAnimal;
//     delete wrongCat;

//     return 0; 
// }
