#ifndef FILENAME_HPP
# define FILENAME_HPP
// #pragma once//C++98 doesnt support

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Filename
{
   public:
    Filename();
    ~Filename();

    void replaceNWriteToFile(filename, s1, s2);

    // private:

};

#endif 