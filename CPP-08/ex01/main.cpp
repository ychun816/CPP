#include "Span.hpp"

int main()
{
    
    try
    {        
        ////EASY TEST
        std::cout << "\n======= SHORT TEST =======" << std::endl;
        Span<int> span1(5);
        span1.addNumber(1);
        span1.addNumber(3);
        span1.addNumber(5);
        span1.addNumber(7);
        span1.addNumber(9);

        std::cout << "\nCurrent Vector Size: " << span1.getVectorSize() << std::endl;
        std::cout << "\n--- 🤏 SHORTEST SPAN 🤏 ---" << std::endl;
        span1.shortestSpan(); //should be 2
        std::cout << "\n--- 🖖 LONGEST SPAN 🖖 ---" << std::endl;
        span1.longestSpan(); //should be 8


        std::cout << "\n\n𓅰 𓅬 𓅭 𓅮 𓅯 𓅰 𓅬 𓅭 𓅮 𓅯 𓅰 𓅬 𓅭 𓅮 𓅯" << std::endl << std::endl;


        ////BIG NB TEST!!!
        std::cout << "\n====== BIG NB TEST!! ======" << std::endl;
        Span<int> span(10000);
        // std::cout << "Added Numbers: ";
        size_t j = 0;
        for (; j < 10000; j++)
        {
            span.addNumber(j);
            // std::cout << j  << ", ";
        }
        // std::cout << j << std::endl;
        std::cout << "\nCurrent Vector Size: " << span.getVectorSize() << std::endl;
        std::cout << "\n--- 🤏 SHORTEST SPAN 🤏 ---" << std::endl;
        span.shortestSpan();
        std::cout << "\n--- 🖖 LONGEST SPAN 🖖 ---" << std::endl;
        span.longestSpan();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}