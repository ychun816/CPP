#include "Serializer.hpp"
#include "Data.hpp"
#include <stdexcept>  //std::invalid_argument

int main()
{
    try {
        std::cout << "=== CREATE DATA ===" << std::endl;
        Data girl("CHOUCHOU", 1, 1000.0);
        std::cout << "Name: " << girl.getName() << std::endl;
        std::cout << "ID: " << girl.getID() << std::endl;
        std::cout << "Score: " << girl.getScore() << std::endl;

        //serialize
        std::cout << "=== SERIALIZE DATA ===" << std::endl;
        uintptr_t num = Serializer::serialize(&girl);
        std::cout << "Serialized data: " << num << std::endl;

        //deserialize
        std::cout << "=== DESERIALIZE DATA ===" << std::endl;
        Data* copy = Serializer::deserialize(num);
        std::cout << "Pointer match: " << (copy == &girl ? "Yes ✅" : "No ❌") << std::endl;
        std::cout << "Deserialized Name: " << copy->getName() << std::endl;
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}