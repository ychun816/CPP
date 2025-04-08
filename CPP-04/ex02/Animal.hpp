#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal 
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type); //construct with type
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
    
        //getter
        std::string getType(void) const;
        
        //membber funcs
        virtual void makeSound(void) const;
        virtual void tellIdea(void) const;
};

#endif
