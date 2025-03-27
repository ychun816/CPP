#include "Inherit.hpp"

Animal::Animal(){}
Animal::~Animal(){}

void Animal::eat()
{
    std::cout << "I am eating..." << std::endl;
}

void Animal::sleep()
{
    std::cout << "I am sleeping..." << std::endl;
}

Dog::Dog(){}
Dog::~Dog(){}
void Dog::bark()
{
    std::cout << "Woof! Woof!" << std::endl;
}

Bird::Bird(){}
Bird::~Bird(){}
void Bird::chirp()
{
    std::cout << "Chirp! Chirp!" << std::endl;
}


int main()
{
    Dog myDog;
    Bird aBird;

    myDog.eat();
    aBird.eat();
    myDog.bark();
    aBird.chirp();
    myDog.sleep();
    aBird.sleep();

}