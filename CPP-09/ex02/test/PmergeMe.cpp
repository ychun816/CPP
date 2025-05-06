#include "PmergeMe.hpp"

std::vector<int> checkInput(int ac, char* av[]) {
    std::vector<int> input;
    for (int i = 1; i < ac; ++i) {
        std::string arg(av[i]);
        if (arg.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Error");

        int value = std::atoi(av[i]);
        if (value < 0)
            throw std::invalid_argument("Error");

        if (std::find(input.begin(), input.end(), value) != input.end())
            throw std::invalid_argument("Error");

        input.push_back(value);
    }
    return input;
}
