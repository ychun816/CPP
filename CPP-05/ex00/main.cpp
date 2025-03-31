#include "Bureaucrat.hpp"

//A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade)
//since grade 1 is the highest and 150 the lowest,
//incrementing a grade 3 should result in a grade 2 for the bureaucrat.

int main()
{

    //normal dude
    std:: cout << std::endl;
    try
    {
        std::cout << "==== Create a Dude ====" << std::endl;
        Bureaucrat validPerson("NORMAL DUDE", 10);//init with name and grade
        std::cout << validPerson << std::endl;

        std::cout << "==== decrement by 1 ====" << std::endl;
        validPerson.decrementGrade();
        std::cout << validPerson << std::endl;

        std::cout << "==== increment by 2 ====" << std::endl;
        validPerson.incrementGrade();
		validPerson.incrementGrade();
        std::cout << validPerson << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    //too high -> 1 
    std:: cout << "\n𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊" << std::endl;
    try
    {
        std::cout << "==== Create a Dude ====" << std::endl;
        Bureaucrat validPerson("HIGH DUDE", 1);//init with name and grade
        std::cout << validPerson << std::endl;

        std::cout << "==== decrement by 1 ====" << std::endl;
        validPerson.decrementGrade();
        std::cout << validPerson << std::endl;

        std::cout << "==== increment by 2 ====" << std::endl;
        validPerson.incrementGrade();
		validPerson.incrementGrade();
        std::cout << validPerson << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    //too low -> 150
    std:: cout << "\n𓇼 ⋆.˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ˚ 𓆉 𓆝 " << std::endl;
    try
    {
        std::cout << "==== Create a Dude ====" << std::endl;
        Bureaucrat validPerson("LOW DUDE", 150);//init with name and grade
        std::cout << validPerson << std::endl;

        std::cout << "==== decrement by 1 ====" << std::endl;
        validPerson.decrementGrade();
        std::cout << validPerson << std::endl;

        // std::cout << "==== increment by 2 ====" << std::endl;
        // validPerson.incrementGrade();
		// validPerson.incrementGrade();
        // std::cout << validPerson << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


/*
The thrown exceptions must be catchable using try and catch blocks:abs

try
{
    //do some stuff with bureaucrats
}
catch (std::exception & e)
{
    //handle exception
}

*/