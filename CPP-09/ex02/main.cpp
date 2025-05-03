#include "PmergeMe.hpp"


int main(int ac, char* av[]) 
{
    // Input: Accept a sequence of integers
    if (ac < 2) 
    {
        std::cerr << "Usage: ./PmergeMe <list of positive integers>" << std::endl;
        return 1;
    }

    try 
    {
        std::vector<int> numbers;
        numbers = checkInput(ac, av);
    
        std::cout << "Before: ";
        printContainer(numbers);
    
        // Sorting using Ford-Johnson algorithm
        fordJohnsonSort(numbers);
    
        std::cout << "After: ";
        printContainer(numbers);

        //print the time taken => TO FIX THE TIMEEEE
        // double timeVec = timer(numbers, "vector");
        // double timeDeq = timer(numbers, "deque");
        // std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector : ";
        // std::cout << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
        // std::cout << "Time to process a range of " << numbers.size() << " elements with std::deque : ";
        // std::cout << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;    


    }
    catch (const std::invalid_argument& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    
    // Timing the sorting process
    // timer(input, "vector");
    // timer(input, "deque");
    // //print time
    // std::cout << "Time to process a range of with " << numbers.size() << " std::vector : " << timer(numbers, "vector") << " us" << std::endl;
    // std::cout << "Time to process a range of with " << numbers.size() << " std::deque : " << timer(numbers, "deque") << " us" << std::endl;
            
    return 0;
}




/*
int main(int ac, char *av[]) 
{
    if (ac < 2) {
        std::cerr << "Error: Not enough arguments!" << std::endl;
        return 1;
    }

    try {
        // Step 1: Check input and parse it
        std::vector<int> input = checkInput(ac, av);

        // Step 2: Display the unsorted sequence
        std::cout << "Before: ";
        printContainer(input);

        // Step 3: Measure and print the time taken for std::vector
        double vector_time = timer(input, "vector");

        // Step 4: Display the sorted sequence (vector)
        std::cout << "After: ";
        printContainer(input);

        // Step 5: Measure and print the time taken for std::deque
        std::deque<int> deque_input(input.begin(), input.end()); // Copy input to deque
        double deque_time = timer(deque_input, "deque");

        // Display the time taken for both containers
        std::cout << "Time to process a range of " << input.size() << " elements with std::vector : ";
        std::cout << std::fixed << std::setprecision(5) << vector_time << " us" << std::endl;
        
        std::cout << "Time to process a range of " << input.size() << " elements with std::deque : ";
        std::cout << std::fixed << std::setprecision(5) << deque_time << " us" << std::endl;
    } catch (const std::invalid_argument& e) 
    {
        // Handle invalid input errors
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
*/


// int main(int ac, char *av[])
// {
//     // if (ac < 2)
//     // {
//     //     std::cerr << "Error: No arguments provided." << std::endl;
//     //     return 1;
//     // }

//     try
//     {
//         std::vector<int> input = checkInput(ac, av);

//         //start
//         std::cout << "Before: ";
//         printContainer(input);

//         //timer 
//         fordJohnsonSort(input);
//         double timeVec = timer(input, "vector");
//         double timeDeq = timer(input, "deque");
        
//         //sort
//         std::vector<int> sorted = input;
//         fordJohnsonSort(sorted);

//         //after - result
//         std::cout << "After: ";
//         printContainer(sorted);

//         //print time taken
//         std:: cout << "Time taken with vector: [ " << timeVec << " ] seconds" << std::endl;
//         std:: cout << "Time taken with deque: [ " << timeDeq << " ] seconds" << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//         return 1;
//     }

//     return 0;
// }