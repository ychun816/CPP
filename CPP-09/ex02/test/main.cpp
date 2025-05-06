#include "PmergeMe.hpp"  // Include the header file

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>  // For std::atoi (C++98 standard)

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe <list of integers>" << std::endl;
        return 1;
    }

    // Call checkInput to process input
    std::vector<int> inputVec = checkInput(ac, av);
    std::deque<int> inputDeq(inputVec.begin(), inputVec.end()); // Copy input into a deque

    // Display the "Before" output for vector
    std::cout << "Before : "; //(vector)
    for (unsigned int i = 0; i < inputVec.size(); ++i) {
        std::cout << inputVec[i] << " ";
    }
    std::cout << std::endl;

    // Display the "After" output for vector (after sorting)
    std::cout << "After : ";//(vector)
    for (unsigned int i = 0; i < inputVec.size(); ++i) {
        std::cout << inputVec[i] << " ";
    }
    std::cout << std::endl;

    // Timer for std::vector sorting
    double timeVec = timer(inputVec); // Sort the vector and measure time
    std::cout << "Time to process a range of " << inputVec.size() << " elements with std::vector : " 
              << timeVec << " us" << std::endl;


    // // Display the "Before" output for deque
    // std::cout << "Before (deque): ";
    // for (unsigned int i = 0; i < inputDeq.size(); ++i) {
    //     std::cout << inputDeq[i] << " ";
    // }
    // std::cout << std::endl;

    // // Display the "After" output for deque (after sorting)
    // std::cout << "After (deque): ";
    // for (unsigned int i = 0; i < inputDeq.size(); ++i) {
    //     std::cout << inputDeq[i] << " ";
    // }
    // std::cout << std::endl;

    // Timer for std::deque sorting
    double timeDeq = timer(inputDeq); // Sort the deque and measure time
    std::cout << "Time to process a range of " << inputDeq.size() << " elements with std::deque : " 
              << timeDeq << " us" << std::endl;


    return 0;
}
