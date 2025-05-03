#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    try
    {
        std::vector<int> input = checkInput(ac, av);

        //start
        std::cout << "Before: ";
        printContainer(input);

        //timer 
        mergeInsertionSort(input);
        double timeVec = timer(input, "vector");
        double timeDeq = timer(input, "deque");
        
        //sort
        std::vector<int> sorted = input;
        mergeInsertionSort(sorted);

        //after - result
        std::cout << "After: ";
        printContainer(sorted);

        //print time taken
        std:: cout << "Time taken with vector: [ " << timeVec << " ] seconds" << std::endl;
        std:: cout << "Time taken with deque: [ " << timeDeq << " ] seconds" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}