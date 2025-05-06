#include "PmergeMe.hpp"

// Check input
// - check if positive int
// - check no dups
std::vector<int> checkInput(int ac, char *av[]) {
    std::vector<int> input;

    for (int i = 1; i < ac; i++) {
        int args = std::atoi(av[i]);
        if (args < 0)
            throw std::invalid_argument("Error: Negative numbers not allowed.");
        if (std::find(input.begin(), input.end(), args) != input.end())
            throw std::invalid_argument("Error: Duplicated numbers not allowed.");
        input.push_back(args);
    }
    return input;
}

// Ford-Johnson template function
template <typename Container>
void fordJohnsonSort(Container& container) {
    size_t n = container.size();
    if (n <= 1) return;

    // Step 1: Pair elements and divide into "larger" and "smaller" arrays
    std::vector<int> larger, smaller;

    for (size_t i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            if (container[i] > container[i + 1]) {
                larger.push_back(container[i]);
                smaller.push_back(container[i + 1]);
            } else {
                larger.push_back(container[i + 1]);
                smaller.push_back(container[i]);
            }
        } else {
            larger.push_back(container[i]);
        }
    }

    // Step 2: Recursively sort the larger elements
    std::sort(larger.begin(), larger.end());

    // Step 3: Inserting the smaller elements using binary insertion
    for (size_t i = 0; i < smaller.size(); ++i) {
        binaryInsert(larger, smaller[i]);
    }

    // Step 4: Copy back to original container
    container = larger;
}

// Binary insert after 
template <typename Container, typename T>
void binaryInsert(Container& container, const T& value) {
    typename Container::iterator pos = std::lower_bound(container.begin(), container.end(), value);
    container.insert(pos, value);
}

// Print container
template <typename Container>
void printContainer(const Container& container) {
    typename Container::const_iterator it;
    for (it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// Timer function
template <typename Container>
double timer(Container& input) {
    clock_t start = 0, end = 0;
    double duration;

    start = clock();
    fordJohnsonSort(input);
    end = clock();

    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds
    return duration;
}
