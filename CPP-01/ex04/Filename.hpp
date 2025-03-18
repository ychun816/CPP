#ifndef FILENAME_HPP
# define FILENAME_HPP
// #pragma once//C++98 doesnt support

#include <iostream>
#include <string>
#include <fstream> //file handling library
#include <sstream>

class Filename
{
   public:
        Filename();
        ~Filename();

        void replaceNWriteToFile(std::string filename, std::string s1, std::string s2);
};

#endif 