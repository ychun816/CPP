#include "PmergeMe.hpp"

int main(int ac, char* av[]) 
{
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe <positive integers>" << std::endl;
        return 1;
    }

    try {
        std::vector<int> vec = checkInput(ac, av);
        std::deque<int> deq(vec.begin(), vec.end());

        std::cout << "Before: ";
        printContainer(vec);

        double timeVec = timer(vec, "vector");
        double timeDeq = timer(deq, "deque");

        std::cout << "After: ";
        printContainer(vec);

        std::cout << "Time to process a range of " << vec.size()
                  << " elements with std::vector : " << std::fixed << std::setprecision(5)
                  << timeVec << " us" << std::endl;

        std::cout << "Time to process a range of " << deq.size()
                  << " elements with std::deque : " << std::fixed << std::setprecision(5)
                  << timeDeq << " us" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
