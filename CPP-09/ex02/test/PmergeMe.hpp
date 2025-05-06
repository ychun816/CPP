#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <exception>
#include <ctime>

// Template function declarations
template <typename Container>
void fordJohnsonSort(Container& container);

template <typename Container>
void printContainer(const Container& container);

template <typename Container>
double timer(Container& input);

// Declare the checkInput function
std::vector<int> checkInput(int ac, char **av);

// Include the template implementation file
#include "PmergeMe.tpp"

#endif
