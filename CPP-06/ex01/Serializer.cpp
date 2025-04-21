#include "Serializer.hpp"

//converts the pointer to a uintptr_t, which is an unsigned integer type that can safely hold a pointer as a number.
uintptr_t Serializer::serialize(Data* ptr)
{
    if (ptr == NULL)
        throw std::invalid_argument("Pointer cannot be NULL.");
    return reinterpret_cast<uintptr_t>(ptr);
}

//converts the uintptr_t back to a pointer of type Data*.
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}