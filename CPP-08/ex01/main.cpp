#include "Span.hpp"

int main()
{
    
    try
    {
        std::cout << "=== CREATE INT ARRAY ===" << std::endl;
        
        //EASY TEST
        // Span<int> span(5);
        // span.addNumber(1);
        // span.addNumber(3);
        // span.addNumber(5);
        // span.addNumber(7);
        // span.addNumber(9);
        
        //BIG NB!!!
        Span<int> span(10000);
        std::cout << "Added Numbers: ";
        size_t i = 0;
        for (; i < 10000; i++)
        {
            span.addNumber(i);
            std::cout << i - 1 << ", ";
        }
        std::cout << i << std::endl;
        std::cout << "\nCurrent Vector Size: " << span.getVectorSize() << std::endl;
        

        //RANDOM NB!!
        // Seed the random number generator
        // srand(static_cast<unsigned int>(time(0)));
        // Loop to generate 1000 random numbers
        // Span<int> span(1000);
        // std::cout << "Added Numbers: ";
        // for (int i = 0; i < 1000; ++i) 
        // {
        //     // Generate a random number between 1 and 100
        //     int randomNumber = rand() % i + 1;

        //     std::cout << randomNumber << ", ";
        // }
        // std::cout << std::endl;


        std::cout << "\n=== SHORTEST SPAN ===" << std::endl;
        span.shortestSpan();

        std::cout << "\n=== LONGEST SPAN ===" << std::endl;
        span.longestSpan();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}