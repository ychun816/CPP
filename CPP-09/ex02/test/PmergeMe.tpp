#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"
#include <algorithm> // For std::sort

// Template function for sorting using Ford-Johnson algorithm (example)
template <typename Container>
void fordJohnsonSort(Container& container) {
    // Example sorting logic (using std::sort which works for both vectors and deques)
    std::sort(container.begin(), container.end());
}

// Template function for printing container elements
template <typename Container>
void printContainer(const Container& container) {
    typename Container::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Template function for timing the sort
template <typename Container>
double timer(Container& input) {
    clock_t start = 0, end = 0;
    double duration;

    start = clock();
    fordJohnsonSort(input); // Sort the container
    end = clock();

    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
    return duration;
}

#endif
