#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <list> //do i need list? 

#include <iostream>  //std::cout
#include <iomanip>   //std::setw
#include <string>    //std::string
#include <sstream>   //std::stringstream
#include <algorithm> //std::sort //std::lower_bound
#include <iterator>  //std::iterator
#include <cstdlib>   //std::atoi
#include <exception>
#include <ctime>

//helper : parse input
std::vector<int> checkInput(int ac, char *av[]);

//Ford Johnhson template func
template <typename Container>
void mergeInsertionSort(Container& container);

//binary insert after 
template <typename Container, typename T>
void binaryInsert(Container& container, const T& value);

//print container
template <typename Container>
void printContainer(const Container& container);

//timing funcs
double timingContainer(std::vector<int>& input, const std::string& containerType);

#endif

/* TIPS / STEPS:

- No nessesary to use class or objects
- Use free functions (regular functions, not inside a class).
- Pass containers as function arguments (std::vector<int>&, std::deque<int>&, etc.).
- Use template functions to avoid writing the same logic for both vector and deque.

//better flexible implementation -> create template function to apply both vector & deque!!

*/