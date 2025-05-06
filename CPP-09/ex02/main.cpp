#include "PmergeMe.hpp"
#include <iomanip> // For std::setprecision and std::fixed

int main(int ac, char* av[]) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        // Input parsing
        std::vector<int> input = checkInput(ac, av);

        std::cout << "Before: ";
        printContainer(input);

        // Create copies for both vector and deque
        std::vector<int> vec = input;
        std::deque<int> deq(input.begin(), input.end());

        // Timer function calls without the second argument (container type)
        double vecTime = timer(vec);
        double deqTime = timer(deq);

        // Printing the sorted vector
        std::cout << "After: ";
        printContainer(vec);

        // Printing the time taken with proper formatting
        std::cout << "Time to process a range of " << vec.size()
                  << " elements with std::vector : " << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
        std::cout << "Time to process a range of " << deq.size()
                  << " elements with std::deque  : " << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
