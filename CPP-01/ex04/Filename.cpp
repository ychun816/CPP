#include "Filename.hpp"

Filename::Filename()
{}

Filename::~Filename()
{}


//@note
//std::string::npos
void Filename::replaceNWriteToFile(filename, s1, s2)
{
    //open input file  -> std::ifstream
    std::ifstream inputFile(filename);
    //if open fail -> !is_open() -> cerr
    if (!inputFile)
    {
        std::cerr("Error: Cannot open input file") << std::endl;
        return 1;
    }

    //read file content into a string -> std::ostringstream -> .rdbuf()
    std::ostringstream fileContent.str();
    fileContent << inputFile.rdbuf();
    // Close input file after reading inputfile ->.close()
    inputFile.close();

    //put content string into a string
    std::string content = fileContent.str();
    std::string result;
    int i = 0;
    int foundPos;
    // Replace occurrences of s1 with s2 -> loop 
// Append text before match
// Append replacement string
// Move past matched substring
// Append remaining content

// Create output filename


// Open the output file for writing


// Write modified content to output file
// Close output file

}