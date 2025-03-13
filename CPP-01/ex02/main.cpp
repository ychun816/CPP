#include <iostream>

/*pointers and references in C++ and how they interact with memory*/


int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;//address of str -> stringPTR stores the memory address of a string
    std::string& stringREF = str;// reference is bound to str -> stringREF => an alias for str

//• The memory address of the string variable.
//• The memory address held by stringPTR.
//• The memory address held by stringREF.
std::cout << "➝ [Memory address]" << std::endl;
std::cout << "✰ string variable: " << &str << std::endl;
std::cout << "✰ stringPTR: " << stringPTR << std::endl;
std::cout << "✰ stringREF: " << &stringREF << std::endl;

std::cout << "⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖" << std::endl;

//The value of the string variable.
//The value pointed to by stringPTR
//The value pointed to by stringREF
std::cout << "➝ [Value]" << std::endl;
std::cout << "✰ value of the string variable: " << str << std::endl;
std::cout << "✰ value pointed to by stringPTR: " << *stringPTR << std::endl;
std::cout << "✰ value pointed to by stringPTR: " << stringREF << std::endl;
}