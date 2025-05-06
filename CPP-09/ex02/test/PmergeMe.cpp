#include "PmergeMe.hpp"
#include <cstdlib>  // For std::atoi

std::vector<int> checkInput(int ac, char **av) {
    std::vector<int> result;

    for (int i = 1; i < ac; ++i) {
        // Convert the string argument to an integer
        int value = std::atoi(av[i]);

        // Check if the value is valid by checking the original input
        if (value == 0 && av[i][0] != '0') {
            std::cerr << "Error: Invalid argument '" << av[i] << "'" << std::endl;
            exit(1);  // Exit on invalid input
        }

        result.push_back(value);
    }
    return result;
}


