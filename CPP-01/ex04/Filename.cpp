#include "Filename.hpp"

////CONSTRUCTOR & DESTRUCTOR
Filename::Filename(){}
Filename::~Filename(){}

/**
 * @note std::ifstream -> open input file
 * @note std::ostringstream -> read file content into a string
 * @note .rdbuf() -> read file content into a string
 * @note .close() -> close input file after reading inputfile
 * @note std::string::npos -> std::string::npos is a constant static member value with the greatest possible value for an element of type size_t
 * @note std::string::find() -> Return position of the first occurrence of substring s1 in the string OR npos if s1 not found
 * @note std::string::substr() -> Return a newly constructed string object with its value initialized to a copy of a substring of this object
 * std::string .substr (size_t pos = 0, size_t len = npos) const;
 * size_t find(const std::string& str, size_t pos = 0) const;
 * size_t find(char ch, size_t pos = 0) const;
*/
/** 
 * 1. OPEN 
 * -If open fail -> std::cerr()
 * 2. READ
 * -Read file content into a string -> std::ostringstream -> .rdbuf()
 * 3. REPLACE
 * -Put content string into a string -> find() the str -> replace by 
 * -Replace occurrences of s1 with s2 -> loop to replace each charset
 * - search s1 starting frm pos(0) & ensure s1 is found
 * [replace]
 * - Append text before match
 * - Append replacement string
 * - Move past matched substring
 * - Append remaining content
 * 4. OUTPUT FILE
 * - Create output filename
 * - Open the output file to write inside
 * - Write modified content to output file
 * - Close output file
 */
void Filename::replaceNWriteToFile(std::string filename, std::string s1, std::string s2)
{
    //OPEN
    std::ifstream inputFile(filename.c_str());// std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open input file" << std::endl;
        return;
    }
    else
    {

        //READ
        std::ostringstream fileContent;//std::ostringstream fileContent.str();
        fileContent << inputFile.rdbuf();
        inputFile.close();

        //REPLACE
        std::string content = fileContent.str();
        std::string result;
        size_t pos = 0;
        size_t foundPos;
        while ((foundPos = content.find(s1, pos)) != std::string::npos)
        {
            result = result + content.substr(pos, foundPos - pos);
            result = result + s2;
            pos = foundPos + s1.length();
        }
        result = result + content.substr(pos);

        //OUTPUT FILE
        std::string outputFilename = filename + ".replace";
        std::ofstream outputFile(outputFilename.c_str());
        if (!outputFile.is_open())
        {
            std::cerr << "Error: Cannot open output file" << std::endl;
            return;
        }
        outputFile << result;
        outputFile.close();
        std::cout << "✅ Replacement complete. Check Output File: " << filename << ".replace" << std::endl;
    }
}

