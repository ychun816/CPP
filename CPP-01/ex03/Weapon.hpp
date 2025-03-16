#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

/*
A private attribute type, which is a string.
• A getType() member function that returns a constant reference to type.
• A setType() member function that sets type using the new value passed as a pa-
rameter.
*/

//They both have a Weapon and a name.
//While HumanA takes the Weapon in its constructor, HumanB does not.
//HumanB may not always have a weapon, whereas HumanA will always be armed.


//Create a simple Weapon class with a private attribute type, a getter, and a setter.
//+References are aliases and cannot be null.
//+Pointers can be null and can be changed to point to something else.

class Weapon
{
    public:
    Weapon(std::string weaponName);
    ~Weapon();

    void setType(std::string weaponType);
    void attack();

    private:
        std::string _weaponName;
};

#endif
/**
Concepts You Need to Learn

Classes & Member Functions
Creating classes with private attributes
Defining getter (getType()) and setter (setType()) functions
Using const references to prevent unnecessary copies
References vs Pointers

References (Weapon &club in HumanA)
Must be initialized at declaration and cannot be null
Changes to the referenced object affect all references to it

Pointers (Weapon *club in HumanB)
Can be null (i.e., HumanB may have no weapon)
Can be reassigned

Constructors & Object Relationships
HumanA gets its Weapon in the constructor (a reference)
HumanB may or may not have a Weapon (a pointer that can be nullptr)

Using const for Safety
Returning const std::string & prevents unnecessary copies
Declaring member functions as const ensures they don’t modify the object

*/

/**
2. Learn About References vs Pointers
References are aliases and cannot be null.
Pointers can be null and can be changed to point to something else.
👉 Practice:

Create a variable and assign a reference and a pointer to it.
Try modifying it using both approaches and observe the differences.
3. Understand How to Use References in Constructors
HumanA must have a weapon at all times → store a reference (Weapon &weapon).
HumanB may have a weapon or not → store a pointer (Weapon *weapon).
👉 Practice:

Write a constructor for HumanA that requires a Weapon &.
Write a constructor for HumanB that can take a Weapon * (or leave it null).
4. Implement the attack() Function
This function prints <name> attacks with their <weapon type>.
Since HumanA always has a weapon, it can directly access weapon.getType().
Since HumanB may not have a weapon, it must check for nullptr.
👉 Practice:

Implement attack() for both HumanA and HumanB.
Test HumanB attacking with and without a weapon.

*/