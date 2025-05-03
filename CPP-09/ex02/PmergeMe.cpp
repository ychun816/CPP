#include "PmergeMe.hpp"

//check input
//- check if positive int
//- check no dups
std::vector<int> checkInput(int ac, char *av[])
{
    std::vector<int> input;

    for (size_t i = 1; i < ac, i++)
    {
        int args = std::atoi(av[i]);
        if (args < 0)
            throw std::invalid_argument("Error : Negative numbers not allowed.");
        if (std::find(input.begin(), input.end(), args) != input.end())
            throw std::invalid_argument("Error : Duplicated numbers not allowed.");
        input.push_back(args);
    }
    return input;
}


//Ford Johnhson template func
template <typename Container>
void mergeInsertionSort(container& container)
{

}



//binary insert after 
template <typename Container, typename T>
void binaryInsert(Container& container, const T& value)
{

}


//print container
template <typename Container>
void printContainer(const Container& container)
{

}


//timing funcs
//clock() : returns the number of clock ticks elapsed since the program started
// CLOCKS_PER_SEC : constant that represents the number of clock ticks per second
//1e6 is scientific notation (floating-point literal) for 1000000.0
// - clock() / CLOCKS_PER_SEC : gives the elapsed time in seconds
//double(end - start) : C style cast 
//static_cast<double>(end - start) :  C++-style cast (more explicit)
double timer(std::vector<int>& input, const std::string& containerType)
{
    clock_t start, end;
    double duration;

    //vector 
    if (containerType == "vector")
    {
        std::vector<int> vec = input;
        start = clock();
        vec.mergeInsertionSort(input);
        end = clock();
    }
    //deque
    else if (containerType == "deque")
    {
        std::deque<int> deq = input;
        start = clock();
        deq.mergeInsertionSort(input);
        end = clock();
    }
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds
    return (duration);
}
