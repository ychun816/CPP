#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal 
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(std::string type);//construct with type
		Cat(const Cat& other);
		Cat& operator=(const Cat &other);
		~Cat();
		
		//member funcs
		void makeSound() const;
		void tellIdea(void) const;

		//getter
		Brain* getBrain() const;
};

#endif