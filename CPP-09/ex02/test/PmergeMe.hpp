#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <list>
#include <iostream>  // std::cout
#include <iomanip>   // std::setw
#include <string>    // std::string
#include <sstream>   // std::stringstream
#include <algorithm> // std::sort, std::lower_bound
#include <iterator>  // std::iterator
#include <cstdlib>   // std::atoi
#include <exception>
#include <ctime>

// Helper: parse input
std::vector<int> checkInput(int ac, char *av[]);

// Ford-Johnson template function
template <typename Container>
void fordJohnsonSort(Container& container);

// Binary insert after 
template <typename Container, typename T>
void binaryInsert(Container& container, const T& value);

// Print container
template <typename Container>
void printContainer(const Container& container);

// Timing functions
template <typename Container>
double timer(Container& input);

#endif
