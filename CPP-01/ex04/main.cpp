#include "Filename.hpp"
// using namespace std;//for "std::"

/** SUBJECT:
 * 1 open the file <filename> and copy its content into a new file <filename>.replace
 * 2 replacing every occurrence of s1 with s2.
 * 3 handle unexpected inputs and errors
 * 4 must create and turn in your own tests
*/

int main(int ac, char *av[])//takes 3 args
{
    Filename file;
    if (ac != 4)
    {
        std::cerr << "Error! Usage: <Filename>, <Sentence>, <Replacer Sentence>" << std::endl;
        return 1;
    }
    //initialzie variables
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    //check filename
    if (filename.empty())
    {
        std::cerr << "Error: The filename cannot be empty." << std::endl;
        return 1;
    }
    //check s1 
    if (s1.empty())
    {
        std::cerr << "Error: The string to be replaced cannot be empty." << std::endl;
        return 1;
    }
    // if (s2.empty())// s2 can be empy! => replace s1 with nothing 
    // {
    //     std::cerr << "Error: The replacer string cannot be empty." << std::endl;
    //     return 1;
    // }
    file.replaceNWriteToFile(filename, s1, s2);
    return 0;
}
