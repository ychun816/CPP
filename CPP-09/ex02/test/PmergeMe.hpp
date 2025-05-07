#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <climits>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <deque>
# include <iomanip>
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

template<typename Container>
void jacobsthalSequence(Container& container, int size);

template<typename Container>
Container PmergeSort(Container& tab);

template<typename Container>
void printContainer(std::ostream& os, const Container& container);

template<typename Container>
std::ostream& operator<<(std::ostream& os, const Container& container);

bool isNumOnly(const char *arg);
std::vector<int> parseArgs(char **av);
void printTimes(int size, double vecTime, double dequeTime, double stdVecTime);
void startSorts(std::vector<int> vec, std::deque<int> deq);

# include "PmergeMe.tpp"

#endif
