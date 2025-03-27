#ifndef INHERIT_HPP
#define INHERIT_HPP

#include <iostream>
#include <string>   

class Animal//parent class
{
    public:
        Animal();
        ~Animal();
        void eat();
        void sleep();
};

class Dog : public Animal //child class
{
    public:
        Dog();
        ~Dog();
        void bark();
};

class Bird : public Animal
{
    public:
        Bird();
        ~Bird();
        void chirp();
};

#endif