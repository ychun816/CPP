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
    (void)av;
    if (ac < 3)
    {
        std::cerr << "Error! Usage: <Filename>, <Sentence>, <Replacer Sentence>" << endl;
        return 1;
    }
    
    //initialzie variables
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    //check s1 
    if (s1.empty())
    {
        std::cerr << "The string to replace cannot be empty." << std::endl;
        return 1;
    }

    //replace and write file
    replaceNWriteToFile(filename, s1, s2);
    std::cout << "Replacement complete. Output file: " << filename << ".replace" << std::endl;
    return 0;

}

//OG
// int main(int ac, char *av[])//takes 3 args
// {
//     (void)av;
//     if (ac < 3)
//     {
//         std::cerr << "Error! Usage: <Filename>, <Sentence>, <Replacer Sentence>" << endl;
//         return 1;
//     }

//     //initialzie variables
//     std::string filename = av[1];
//     std::string s1 = av[2];
//     std::string s2 = av[3];
//     // Open input file
//     std::ifstream inputFile(filename);
//     if (!inputFile.is_open())
//     {
//         std::cerr << "Error: Cannot open file" << std::endl;
//         return 1;
//     }
//     //Read the content in input file into a str
//     std::ostringstream fileContent;
//     //reads the entire file content into a string buffer
//     fileContent << inputFile.rdbuf();
//     if (!fileContent)
//     {
//         std::cerr << "Error: Cannot read file" << std::endl;
//         return 1;
//     }
//     //extract file content into string(content)
//     std::string content = fileContent.str();
//     //Close input file
//     inputFile.close();
//     // Replace s1 with s2(replacer)
//     size_t foundPos = content.find(s1, pos);
//     //Write to the output file
//     std::ofstream outputFile(filename + ".replace");
//     if (!outputFile.is_open())
//     {

//     }
//     //confirm save in new filename
//     std::cout << "File processed and saved in " << filename << ".replace" << endl;
//     return 0;
// }
//print out to check
// cout << "Filename: " << filename << endl;
// cout << "Sentence: " << s1 << endl;
// cout << "Replacer Sentence: " << s2 << endl;