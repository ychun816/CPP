#include "PmergeMe.hpp"
 
        // std::deque<int> deque;
        // std::vector<int> vector;
        // std::vector<std::string> strs; //Store input arguments as strings for validation



PmergeMe::PmergeMe(){} //: _isOdd(false), odd(0) 

PmergeMe::PmergeMe(PmergeMe const &src) //: _isOdd(src._isOdd), odd(src.odd)
{
   *this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& src)
{
    if (this != &src)
    {
        this->_dequeData = src._dequeData;
        this->_vectorData = src._vectorData;
        this->_input = src._input;
        // this->deque = src.deque;
        // this->vector = src.vector;
        // this->strs = src.strs;
        // this->_isOdd = src._isOdd;
        // this->odd = src.odd;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

//////////////////////////////////////////////

template <typename Container>
void print(Container& container)
{
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
        std::cout << "(" << it->first << ", " << it->second << ") ";
    std::cout << std::endl; 
}

//error msg 
bool errorMsg(std::string const& msg)
{
    std::cerr << msg << std::endl;
    return false;
}

//is valid int
bool isValidInt(const std::string& str)
{
    if (str.empty())
        return false;
    
    std::stringstream ss(str);
    int value;
    char remainingChar;
    if (!(ss >> value) || (ss >> remainingChar))
        return false;
    return true;
}

//parse str
bool parseStr(const std::string& input)
{
    std::stringstream ss(input);
    std::string token;
    int i = 0;
    while (ss >> token)
    {
        i++;
        if (!isValidInt(token))
            return false;
    }
    if (i == 0)
        return false;
    return true;
}

////SORTING
//make pairs
template <typename Container, typename PairContainer>
void makePairs(const Container& vec, PairContainer& vecPair)
{
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        vecPair.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
}
// template <typename Container, typename PairContainer>
// void makePairs(const Container& vec, PairContainer& vecPair)
// {
//     for (size_t i = 0; i + 1 < vec.size(); i += 2)
//     {
//         vecPair.push_back(std::make_pair(vec[i], vec[i + 1]));
//     }
// }

// template <typename T, typename T_P>
// void makePairs(T& vec, T_P& vecPair)
// {
//     for (typename T::iterator it = vec.begin(); it != vec.end(); it++)
//     {
//         std::pair<int, int> pair(*it , *(++it));
//         vecPair.push_back(pair);
//     }
//     return ;
// }

//sort pairs 
template <typename T_P>
void sortPairs(T_P& vecPair)
{
    for (typename T_P::iterator it = vecPair.begin(); it != vecPair.end(); it++)
    {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
    return;
}

//sort vec pairs 
template <typename T_P>
void sortVecPairs(T_P& vecPair)
{
    if (vecPair.size() <= 1)
        return;
   typename T_P::iterator mid = vecPair.begin() + (vecPair.size() / 2);
    
    T_P left(vecPair.begin(), mid);
    T_P right(mid, vecPair.end());
    sortVecPairs(left);
    sortVecPairs(right);
    
    typename T_P::iterator l = left.begin();
    typename T_P::iterator r = right.begin();
    
    int i = 0;
    while (l != left.end() && r != right.end())
    {
        if (l->second < r->second)
        {
            vecPair[i] = *l;
            l++;
        }
        else
        {
            vecPair[i] = *r;
            r++;
        }
        i++;
    }
    while(l != left.end())
    {
        vecPair[i++] = *l++;
    }
    while(r != right.end())
    {
        vecPair[i++] = *r++;
    }
}

//place all greater
template <class Container, class C_P>
void placeAllGreater(Container& vec, C_P& vecPair)
{
    for(typename C_P::const_iterator it = vecPair.begin(); it != vecPair.end(); it++)
        vec.push_back(it->second);
}

//get pair value
template <class C_P>
std::pair<int, int> getPairValue(const std::vector<int>& jacobPair, C_P& vecPair)
{    
    int jacobValue = jacobPair.back();
    std::pair<int, int> value2Insert = std::make_pair(
        vecPair[jacobValue].first, vecPair[jacobValue].second
    );
    vecPair.erase(vecPair.begin() + jacobValue);
    return value2Insert;
}
// template <class C_P>
// std::pair<int, int> getPairValue(std::vector<int> jacobPair, C_P& vecPair)
// {    
//     std::pair<int, int> value2Insert;

//     int jacobValue = jacobPair.back();
//     value2Insert = makePairs(vecPair[jacobValue].first, vecPair[jacobValue].second); 
//     vecPair.erase(vecPair.begin() + jacobValue);
//     return value2Insert;
// }

//find int vector
template <class Container>
int findInVector(Container& vec, int value)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
            return i;
    }
    return vec.size();
}

//binary search insert
template <class Container>
int binarySearchInsert(Container& vec, std::pair<int, int> pairValue, std::vector<int>& jacob)
{
    int value = pairValue.first;
    int n = findInVector(vec, pairValue.second); //check again? 
    int jacobSize = jacob.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    
    while(low <= high)
    {
        jacobSize--;
        if(jacobSize < 0)
            mid = low;
        else
            mid = low + jacob[jacobSize];
        if (mid >= n)
            mid = n - 1;
        if (vec[mid] == value)
            return (mid);
        else if(vec[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return(low);
}


//generate jacobsthal
std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    if(n == 1)
    {
        jacobsthal.pop_back();
        return jacobsthal;
    }
    while (jacobsthal.back() < n) 
    {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        
        if (next >= n) 
            break;
        
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

//insert in order 
template <class Container>
void insertInOrder(Container& vec, std::pair<int, int> value)
{
    int size = vec.size();
    std::vector<int> jacobsthal = generateJacobsthal(size);
    int pos = binarySearchInsert(vec, value, jacobsthal);
    vec.insert(vec.begin() + pos, value.first);
}

//ford johnson 
template <class Container, class C_P>
void FordJohnson(Container& vec, C_P& vecPair)
{
    std::vector<int> jacobPair;
    std::pair<int, int> value2Insert;

    int nbPair = vecPair.size();
    
    vec.clear();

    placeAllGreater(vec, vecPair);
    
    for (; nbPair > 0;)
    {
        jacobPair = generateJacobsthal(nbPair);
        value2Insert = getPairValue(jacobPair, vecPair);
        insertInOrder(vec, value2Insert);
        nbPair = vecPair.size();
    }
}

template<class Container, class C_P>
void mergeInsertSort(Container &vector, C_P &vecPair)
{
    bool isOdd = vector.size() % 2;
    std::pair<int, int> odd;

    if(isOdd)
    {
        odd.first = vector.back();
        odd.second = ODD_INT; //2147483647
        vector.pop_back();
    }
    makePairs(vector, vecPair);
    sortPairs(vecPair);
    sortVecPairs(vecPair);
    
    FordJohnson(vector, vecPair);
    if(isOdd)
        insertInOrder(vector, odd);
}

//////////////////////////////

template <class Container>
void printContainer(Container vec, bool started)
{
    (void)vec;
    if (!started)
        std::cout << "Before start: ";
}


void printTime(clock_t start, clock_t end, std::string const& containerType, int size)
{
    double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

     std::cout << "Time to process a range of " << size << " elements with std::" << containerType  << ": " 
        << std::fixed << timeTaken << " sec" << std::endl;
}


////MEMBER FUNCS
bool PmergeMe::initContainers(int ac, char *av[])
{
    if (ac < 3)
        return errorMsg("Usage: ./PmergeMe [Positive Integers <nb1> <nb2> <nb3> ...]\n");

    for (int i = 1; i < ac; i++)
    {
        std::string arg(av[i]);
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(arg[j]))
            {
                std::cerr << "Error: Invalid input [" << arg << "]" << std::endl;
                return false;
            }
        }
        int num = std::atoi(av[i]);
    
        // Updated member name
        _dequeData.push_back(num);   
        _vectorData.push_back(num);  
        _input.push_back(arg);
    }

    if (hasDuplicate())
    {
        std::cerr << "Error: Duplicate integer found." << std::endl;
        return false;
    }
    return true;   
    // for (int i = 1; i < ac; i++)
    //     strs.push_back(av[i]);


    // for (std::vector<std::string>::iterator it = strs.begin(); it != strs.end(); it++)
    // {
    //     if (!parseStr(*it))
    //         return errorMsg("Error: Invalid Input. Usage: ./PmergeMe [Positive Integers]\n");
    //     deque.push_back(std::atoi(it->c_str()));
    // }
    // this->vector.assign(this->deque.begin(),this->deque.end());
    // if (hasDuplicate())
    //     return errorMsg("Error: Duplicated values found.\n");
    // return true;
}


bool PmergeMe::hasDuplicate() const
{
    std::set<int> seen;

    for (size_t i = 0; i < _input.size(); ++i)
    {
        int value = std::atoi(_input[i].c_str());
        if (seen.find(value) != seen.end())
            return true;
        seen.insert(value);
    }
    return false;
    // for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    // {
    //     if (seen.find(*it) != seen.end())
    //         return true;
    //     seen.insert(*it);
    // }
    // return false;
}

void PmergeMe::execute(int ac, char *av[])
{
        if (!initContainers(ac, av)) return;

    std::cout << "Before start: ";
    for (size_t i = 0; i < _vectorData.size(); ++i)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;

    // Time vector sort
    clock_t startVec = clock();
    std::sort(_vectorData.begin(), _vectorData.end());
    clock_t endVec = clock();

    // Time deque sort
    clock_t startDeq = clock();
    std::sort(_dequeData.begin(), _dequeData.end());
    clock_t endDeq = clock();

    std::cout << "After start: ";
    for (size_t i = 0; i < _vectorData.size(); ++i)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;

    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << _vectorData.size()
              << " elements with std::vector: "
              << std::fixed << std::setprecision(6) << vecTime << " sec" << std::endl;

    std::cout << "Time to process a range of " << _dequeData.size()
              << " elements with std::deque: "
              << std::fixed << std::setprecision(6) << deqTime << " sec" << std::endl;

    /*
    if (!initContainers(ac, av)) // 🔍 If this function modifies the object, leave as-is
        return;

    // Example: Perform operations on deque/vector here
    std::sort(_vectorData.begin(), _vectorData.end()); // Renamed from `vector`
    std::sort(_dequeData.begin(), _dequeData.end());   // Renamed from `deque`

    // Print results for testing
    std::cout << "Sorted Vector: ";
    for (std::vector<int>::const_iterator it = _vectorData.begin(); it != _vectorData.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Sorted Deque: ";
    for (std::deque<int>::const_iterator it = _dequeData.begin(); it != _dequeData.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    */
}
// void PmergeMe::execute(int ac, char *av[])
// {
//     // std::vector<std::pair<int, int> > vecPair;
//     // std::deque<std::pair<int, int> > deqPair;
//     vecPair vecPair;
//     deqPair deqPair;
//     clock_t start;
//     clock_t end;


//     if (!initContainers(ac, av))
//         return;
    
//     //vector
//     printContainer(this->vector, false);
//     start = clock();
//     mergeInsertSort(this->vector, vecPair);
//     end = clock();
//     printContainer(this->vector, true);
//     printTime(start, end, "vector", this->vector.size());


//     //deque
//     printContainer(this->deque, false);
//     start = clock();
//     mergeInsertSort(this->deque, deqPair);
//     end = clock();
//     printContainer(this->deque, true);
//     printTime(start, end, "deque", this->deque.size());
// }

/*
𓂃𓂃𓂃𓊝 ࿐𓂃𓂃𓂃
𓇼 ⋆.˚  𓆝⋆.˚    𓇼 ⋆｡˚ 𓆞
𓆉𓆝𓇼𓆟  𖦹°‧𓆝𓆡𓆜

*/


