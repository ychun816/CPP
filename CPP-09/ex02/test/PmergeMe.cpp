#include "PmergeMe.hpp"

void printTimes(int size, double vecTime, double dequeTime, double stdVecTime) {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << vecTime << " s\n";
    std::cout << "Time to process a range of " << size << " elements with std::deque  : " << dequeTime << " s\n";
    std::cout << "Time for std::sort() to process a range of " << size << " elements  : " << stdVecTime << " s\n";
}

void startSorts(std::vector<int> vec, std::deque<int> deq) {
    std::cout << "Before: " << vec << std::endl;

    std::clock_t start, end;
    double vecTime, deqTime, stdVecTime;

    std::vector<int> stdSortVec = vec;
    start = std::clock();
    std::sort(stdSortVec.begin(), stdSortVec.end());
    end = std::clock();
    stdVecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = std::clock();
    vec = PmergeSort(vec);
    end = std::clock();
    vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = std::clock();
    deq = PmergeSort(deq);
    end = std::clock();
    deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "After:  " << vec << std::endl;

    printTimes(vec.size(), vecTime, deqTime, stdVecTime);
}

bool isNumOnly(const char *arg) {
    for (int i = 0; arg[i] != '\0'; ++i) {
        if (!std::isdigit(arg[i]))
            return false;
    }
    return true;
}

std::vector<int> parseArgs(char **av) {
    std::vector<int> tab;
    long long num;
    for (int i = 0; av[i]; ++i) {
        if (av[i][0] == '-')
            throw std::invalid_argument("Error: only positive numbers allowed");
        if (!isNumOnly(av[i]))
            throw std::invalid_argument("Error: unrecognized argument");

        num = std::atoll(av[i]);
        if (num > INT_MAX)
            throw std::invalid_argument("Error: number too large");
        tab.push_back(static_cast<int>(num));
    }
    return tab;
}
