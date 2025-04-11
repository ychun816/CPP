#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

//Animal class change to abstract class -> virtual destructor
//make pure virtual function
class AAnimal 
{
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(std::string type); //construct with type
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal();
    
        //getter
        std::string getType(void) const;
        
        //member funcs
        virtual void makeSound(void) const = 0;
        virtual void tellIdea(void) const = 0;
};

#endif
