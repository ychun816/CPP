#include "Cat.hpp"

/*tryout*/
#include "Cat.hpp"

Cat::Cat() /*: Animal()*/ {
	_type = "defaultCat";
	std::cout << "Cat " << _type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) /*: Animal(other)*/ {
	 *this = other;
	std::cout << "Cat " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other){
		Animal::operator=(other);
	}
	std::cout << "Cat " << _type << " has been assigned!" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat makes a sound" << std::endl;
}


/*OG
//con-de structs
Cat::Cat()//default construct
{
    _type = "Cat";
    std::cout << "Cat " << _type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)  // Properly call base class copy constructor
{
    _type = other._type;
    std::cout << "Cat " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other)  // Correct assignment operator
{
    if (this != &other)
    {
        Animal::operator=(other);  // Call base class assignment
        _type = other._type;
    }
    std::cout << "Cat " << _type << " has been assigned!" << std::endl;
    return *this;
}
// Cat::Cat(const Cat& other) : _type(other._type) //copy
// {
//     // *this = other;//_type = other._type;  // Manually copying the member variable
//     std::cout << "Cat " << _type << " has been copied" << std::endl;
// }

// Cat& Cat::operator=(const Cat& other)//assign operator
// {
//     if (this != &other)
//         Animal::operator=(other); //ensure the base class data is copied properly in the assignment operator of the derived class (Cat).
//         // _type = other._type;//!CANNOT USE! //only the derived class data will be copied, and base class data (if any) would be lost.
//     std::cout << "Cat " << _type << " has been assigned!" << std::endl;
//     return (*this);
// }

Cat::~Cat()//destruc
{
    std::cout << "Cat is destroyed" << std::endl;
}

//funcs
void Cat::makeSound(void) const
{
    std::cout << "Cat makes sound: Meow~~~" << std::endl;
}
*/