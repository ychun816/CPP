#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "==== Create Valid Person A ====" << std::endl;
        Bureaucrat validPerson("BOB🧞", 10);
        Form goodForm("GOOD CONTRACT📝", 11, 11);//signable , executable
        validPerson.signForm(goodForm);
        std::cout << goodForm << std::endl;


        std::cout << "==== Create Invalid Person B ====" << std::endl;
        Bureaucrat invalidPerson("TOM🧜", 12);
        Form badForm("BAD CONTRACT📝", 5, 5);//not signable , not executable
        invalidPerson.signForm(badForm);
        std::cout << badForm << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

        // std::cout << "==== Create Invalid Person B ====" << std::endl;
        // Bureaucrat invalidPerson("TOM🧜", 12);
        // Form badForm("BAD CONTRACT📝", 5, 5);//not signable , not executable
        // invalidPerson.signForm(badForm);
        // std::cout << badForm << std::endl;

    return 0;
}
