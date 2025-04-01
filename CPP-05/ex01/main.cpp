#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "==== Create a Person A ====" << std::endl;
        Bureaucrat validPerson("BOB", 10);
        Form signableForm("CONTRACT", 11, 11);//signable , executable
        std::cout << signableForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

/*
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

*/