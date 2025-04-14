#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "==== Create a Person A ====" << std::endl;
        Bureaucrat validPerson("BOB🧞", 10);
        Form signableForm("CONTRACT📝", 11, 11);//signable , executable
        std::cout << signableForm << std::endl;

        std::cout << "==== Create a Person B ====" << std::endl;
        Bureaucrat invalidPerson("ANNE🧜", 10);
        Form badForm("CONTRACT📝", 5, 5);//not signable , not executable
        std::cout << signableForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
