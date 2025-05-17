#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <set>
#include <list>

#include <iostream>
#include <string>
#include <iomanip>   //std::setw
#include <sstream>   //std::stringstream
#include <algorithm> //std::sort //std::lower_bound
#include <iterator>  //std::iterator
#include <cstdlib>   //std::atoi
#include <exception>
#include <ctime>

#define ODD_INT 2147483647

// Define shorthand typedefs for vector and deque of pairs of integers
// std::vector<std::pair<int, int> > vecPair;
// std::deque<std::pair<int, int> > deqPair;
typedef std::vector<std::pair<int, int> > vecPair; 
typedef std::deque<std::pair<int, int> > deqPair;  


class PmergeMe
{
    protected:
        std::deque<int> deque;
        std::vector<int> vector;
        std::vector<std::string> strs; //Store input arguments as strings for validation

        bool initContainers(int ac, char *av[]);
        bool hasDuplicate();
    
    public:
        bool _isOdd; //Flag -> check if number of elements is odd (unused in code)
        int odd;     //Stores odd value (unused in code)

        PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const& src);
        virtual ~PmergeMe();

        void execute(int ac, char *av[]);
};

#endif
