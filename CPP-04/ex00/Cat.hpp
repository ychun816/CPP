#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat &other);
	~Cat();

	void makeSound() const;
};

#endif
// #ifndef CAT_HPP
// #define CAT_HPP

// #include "Animal.hpp"

// //DERIVED CLASS
// class Cat : public Animal
// {
//     public:
//         Cat();//default construct
//         Cat(const Cat& other);//copy
//         Cat& operator=(Cat& other);//assign operator
//         ~Cat();//destruc

//         void makeSound(void) const;
// };

// #endif