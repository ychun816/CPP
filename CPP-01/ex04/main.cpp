#include "Filename.hpp"
// using namespace std;//for "std::"

/** SUBJECT:
//open the file <filename> and copy its content into a new file <filename>.replace
//replacing every occurrence of s1 with s2.
//handle unexpected inputs and errors
//must create and turn in your own tests
*/

int main(int ac, char *av[])//takes 3 args
{
    // (void)av;
    Filename file;
    if (ac < 3)
    {
        std::cerr << "Error! Usage: <Filename>, <Sentence>, <Replacer Sentence>" << std::endl;
        return 1;
    }
    
    //initialzie variables
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    //check s1 
    if (s1.empty())
    {
        std::cerr << "Error: The string to be replaced cannot be empty." << std::endl;
        return 1;
    }
    file.replaceNWriteToFile(filename, s1, s2);
    std::cout << "✅ Replacement complete. Check Output File: " << filename << ".replace" << std::endl;
    return 0;

}
