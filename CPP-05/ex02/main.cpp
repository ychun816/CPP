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
        Bureaucrat highRank("HighRank", 1);       // Can sign and execute all forms
        Bureaucrat midRank("MidRank", 50);       // Can sign and execute some forms
        Bureaucrat lowRank("LowRank", 150);      // Cannot sign or execute most forms

        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubbery("Garden");
        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        try {
            highRank.signForm(shrubbery);
            highRank.executeForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            midRank.signForm(shrubbery);
            midRank.executeForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            lowRank.signForm(shrubbery);
            lowRank.executeForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomy("Target");
        std::cout << "\n--- Testing RobotomyRequestForm ---\n";
        try {
            highRank.signForm(robotomy);
            highRank.executeForm(robotomy);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            midRank.signForm(robotomy);
            midRank.executeForm(robotomy);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            lowRank.signForm(robotomy);
            lowRank.executeForm(robotomy);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Offender");
        std::cout << "\n--- Testing PresidentialPardonForm ---\n";
        try {
            highRank.signForm(pardon);
            highRank.executeForm(pardon);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            midRank.signForm(pardon);
            midRank.executeForm(pardon);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            lowRank.signForm(pardon);
            lowRank.executeForm(pardon);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}