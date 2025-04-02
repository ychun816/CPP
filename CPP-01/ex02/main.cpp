#include <iostream>

/*pointers and references in C++ and how they interact with memory*/

/** 
 * @note std::string* stringPTR = &str;
 * -> Address of str
 * -> Store memory address of a string
 * 
 * @note std::string& stringREF = str;
 * -> Reference is bound to str
 * -> An alias for str
 */

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    //print str
    std::cout << "======= Example STR: " << str << " =======" << std::endl;
    std::cout << std::endl;

    //• Memory address of str variable
    //• Memory address held by stringPTR
    //• Memory address held by stringREF
    std::cout << "➝ [Memory address]" << std::endl;
    std::cout << "✰ Memory address of string variable: " << &str << std::endl;
    std::cout << "✰ Memory address of stringPTR: " << stringPTR << std::endl;
    std::cout << "✰ Memory address of stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖﹏𓂁﹏⊹ ࣪ ˖" << std::endl;

    //Value of str variable.
    //Value pointed to by stringPTR
    //Value pointed to by stringREF
    std::cout << std::endl;
    std::cout << "➝ [Value]" << std::endl;
    std::cout << "✰ value of the string variable: " << str << std::endl;
    std::cout << "✰ value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "✰ value pointed to by stringREF: " << stringREF << std::endl;
}