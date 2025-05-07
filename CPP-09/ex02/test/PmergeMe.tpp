#ifndef PMERGEME_TPP
#define PMERGEME_TPP

template<typename Container>
void jacobsthalSequence(Container& container, int size) {
    if (size <= 0)
        return;

    container.push_back(0);
    int last = 0;
    bool finished = false;

    for (int n = 1; !finished; ++n) {
        int j = (static_cast<int>(std::pow(2.0, n)) - static_cast<int>(std::pow(-1.0, n))) / 3;
        int temp = last;
        last = j;
        for (; j > temp; --j) {
            if (j < size)
                container.push_back(j);
            else
                finished = true;
        }
    }
}

template<typename Container>
Container PmergeSort(Container& tab) {
    typedef typename Container::value_type T;
    typedef typename Container::iterator Iterator;

    size_t pairs = 0;
    Container result, big, small;
    Iterator it = tab.begin();

    while (it != tab.end()) {
        T n1 = *it;
        ++pairs;
        ++it;

        if (it != tab.end()) {
            T n2 = *it;
            big.push_back(std::max(n1, n2));
            small.push_back(std::min(n1, n2));
            ++it;
        } else {
            small.push_back(n1);
            break;
        }
    }

    if (pairs == 1) {
        result.push_back(small[0]);
        if (!big.empty())
            result.push_back(big[0]);
        return result;
    }

    result = PmergeSort(big);

    Container jacob;
    jacobsthalSequence(jacob, static_cast<int>(small.size()));

    typename Container::iterator jt = jacob.begin();
    for (; jt != jacob.end(); ++jt) {
        int index = *jt;
        if (index < static_cast<int>(small.size())) {
            T val = small[index];
            typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), val);
            result.insert(pos, val);
        }
    }

    return result;
}

template<typename Container>
void printContainer(std::ostream& os, const Container& container) {
    const int MAX_DISPLAY = 4;
    int count = 0;
    typename Container::const_iterator it = container.begin();
    while (it != container.end() && count <= MAX_DISPLAY) {
        os << *it;
        ++it;
        ++count;
        if (it != container.end() && count <= MAX_DISPLAY)
            os << " ";
    }
    if (it != container.end())
        os << " [...]";
}

template<typename Container>
std::ostream& operator<<(std::ostream& os, const Container& container) {
    printContainer(os, container);
    return os;
}

#endif
