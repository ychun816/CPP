#include "Filename.hpp"
using namespace std;//for "std::"

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
        cerr << "Error! Usage: <Filename>, <Sentence>, <Replacer Sentence>" << endl;
        return 1;
    }

    //initialzie variables
    string filename = av[1];
    string s1 = av[2];
    string s2 = av[3];
    // Open input file
    
    //Read the content in input file into a str

    //Close input file

    // Replace s1 with s2(replacer)

    //Write to the output file
    
    //confirm save in new filename
    cout << "File processed and saved in " << filename << ".replace" << endl;
    return 0;
}
//print out to check
// cout << "Filename: " << filename << endl;
// cout << "Sentence: " << s1 << endl;
// cout << "Replacer Sentence: " << s2 << endl;