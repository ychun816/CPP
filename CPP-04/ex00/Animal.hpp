#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

/** BASE CLASS
 * @note
 * Base class destructor needs to be virtual when a class is hierarchy with polymorphism
 * If the destructor in base class not virtual -> base class destructor will be called instead of the derived class!!
 * Lead to resource leaks cuz derived class may have allocated resources (e.g., memory, file handles, etc.) that are not cleaned up when the base class destructor is invoked
*/
class Animal 
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type); //construct with type
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();//vitural destructor
    
        virtual void makeSound(void) const;
        std::string getType(void) const;
};

#endif
