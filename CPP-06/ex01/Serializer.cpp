#include "Serializer.hpp"

//serialize
//take a pointer to a Data object -> convert it to an unsigned integer type (uintptr_t)
//an unsigned integer type -> can safely hold a pointer as a number
uintptr_t Serializer::serialize(Data* ptr)
{
    if (ptr == NULL)
        throw std::invalid_argument("Pointer cannot be NULL.");
    return reinterpret_cast<uintptr_t>(ptr);
}

//deserialize
//converts the uintptr_t back to a pointer of type Data*
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}