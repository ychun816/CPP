#include <iostream>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    srand(time(0));

    try {
        // Create bureaucrats with different ranks
        Bureaucrat highRank("HIGH RANK👩", 1);       // Can sign and execute all forms
        Bureaucrat midRank("MID RANK🧝", 50);       // Can sign and execute some forms
        Bureaucrat lowRank("LOW RANK🧟", 150);      // Cannot sign or execute most forms

        // Test ShrubberyCreationForm
        std::cout << "\n=== TEST ShrubberyCreationForm ===\n";
        ShrubberyCreationForm shrub("GARDEN🌱");
        try 
        {
            highRank.signForm(shrub);
            highRank.executeForm(shrub);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            midRank.signForm(shrub);
            midRank.executeForm(shrub);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            lowRank.signForm(shrub);
            lowRank.executeForm(shrub);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        // Test RobotomyRequestForm
        std::cout << "\n=== TEST RobotomyRequestForm ===\n";
        RobotomyRequestForm robot("TARGET🍥");
        try 
        {
            highRank.signForm(robot);
            highRank.executeForm(robot);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            midRank.signForm(robot);
            midRank.executeForm(robot);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            lowRank.signForm(robot);
            lowRank.executeForm(robot);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("VILLAIN🧌");
        std::cout << "\n=== TEST PresidentialPardonForm ===\n";
        try 
        {
            highRank.signForm(pardon);
            highRank.executeForm(pardon);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            midRank.signForm(pardon);
            midRank.executeForm(pardon);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            lowRank.signForm(pardon);
            lowRank.executeForm(pardon);
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}