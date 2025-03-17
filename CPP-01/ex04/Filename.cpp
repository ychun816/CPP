#include "Filename.hpp"

Filename::Filename()
{}

Filename::~Filename()
{}

//@note
//std::string::npos
//std::string .substr (size_t pos = 0, size_t len = npos) const;
//size_t find(const std::string& str, size_t pos = 0) const;
//size_t find(char ch, size_t pos = 0) const;


void Filename::replaceNWriteToFile(std::string filename, std::string s1, std::string s2)
{
    ////OPEN
    //open input file  -> std::ifstream
    std::ifstream inputFile(filename.c_str());// std::ifstream inputFile(filename);
    //if open fail -> !is_open() -> cerr
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open input file" << std::endl;
        return;
    }

    ////READ
    //read file content into a string -> std::ostringstream -> .rdbuf()
    std::ostringstream fileContent;//std::ostringstream fileContent.str();
    fileContent << inputFile.rdbuf();
    // Close input file after reading inputfile ->.close()
    inputFile.close();

    ////REPLACE
    //put content string into a string
    std::string content = fileContent.str();
    std::string result;
    size_t pos = 0;//int?
    size_t foundPos;//int?
    // Replace occurrences of s1 with s2 -> loop to replace each charset
    while ((foundPos = content.find(s1, pos)) != std::string::npos)//search s1 starting frm pos(0) & ensure s1 is found
    {
        result = result + content.substr(pos, foundPos - pos);// Append text before match
        result = result + s2;// Append replacement string
        pos = foundPos + s1.length();// Move past matched substring
    }
    result = result + content.substr(pos);// Append remaining content

    ///OUTPUT FILE
    std::string outputFilename = filename + ".replace";// Create output filename
    // Open the output file to write inside
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot open output file" << std::endl;
        return;
    }
    outputFile << result;// Write modified content to output file
    outputFile.close();// Close output file
}

/*EXAMPLE
std::string content = "Hello world, Hello universe!";
std::string s1 = "Hello";
std::string s2 = "Hi";
*/
