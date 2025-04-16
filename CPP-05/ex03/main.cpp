
// #include <ctime>
#include "AForm.hpp"
// #include "Bureaucrat.hpp"
#include "Intern.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"


#include "Intern.hpp"
#include <iostream>

int main() 
{
    std::cout << "===== CREATE INTERN =====" << std::endl << std::endl;

    // Create an intern
    Intern intern;
    
    std::cout << "\n===== TEST Valid Forms =====" << std::endl;
    
    try 
    {
        // Test Shrubbery Creation Form
        std::cout << "\n===== shrubbery form =====\n" << std::endl;

        AForm& shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
        std::cout << "Created: " << shrubberyForm.getName() << std::endl;
        delete &shrubberyForm;// Remember to clean up!!!
        
        // Test Robotomy Request Form
        std::cout << "\n===== robotomy form =====\n" << std::endl;
        AForm& robotomyForm = intern.makeForm("robotomy request", "Bender");
        std::cout << "Created: " << robotomyForm.getName() << std::endl;
        delete &robotomyForm;
        
        // Test Presidential Pardon Form
        std::cout << "\n===== presidential form =====\n" << std::endl;
        AForm& presidentialForm = intern.makeForm("presidential form", "John Doe");
        std::cout << "Created: " << presidentialForm.getName() << std::endl;
        delete &presidentialForm;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    //INVALID FORM
    std::cout << "\n===== TEST Invalid Forms =====\n" << std::endl;
    try 
    {
        // Test with wrong form name (should throw exception)
        std::cout << "Attempting to create non-existent form..." << std::endl;
        AForm& invalidForm = intern.makeForm("fake form", "Target");
        std::cout << "Created: " << invalidForm.getName() << std::endl;
        delete &invalidForm;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error (expected): " << e.what() << std::endl;
    }

    //EDGE CASE
    std::cout << "\n===== TEST EDGE CASES =====\n" << std::endl;    
    try 
    {
        // Test with empty form name
        std::cout << "Attempting to create form with empty name..." << std::endl;
        AForm& emptyForm = intern.makeForm("", "Nowhere");
        std::cout << "Created: " << emptyForm.getName() << std::endl;
        delete &emptyForm;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error (expected): " << e.what() << std::endl;
    }

    // try 
    // {
    //     // Test with similar but incorrect form name
    //     std::cout << "Attempting to create form with typo..." << std::endl;
    //     AForm& typoForm = intern.makeForm("shrubbery creatio", "Garden");
    //     std::cout << "Created: " << typoForm.getName() << std::endl;
    //     delete &typoForm;
    // } 
    // catch (const std::exception& e) 
    // {
    //     std::cerr << "Error (expected): " << e.what() << std::endl;
    // }
    
    return 0;
}




/*OTHER TESTS

//super simple
int main()
{
    //create intern
    Intern* sophie = new Intern();       
    sophie->makeForm("shrubbery creation", "TARGET");
}

//ref
int	main() 
{
	Bureaucrat *	Donald = new Bureaucrat("Donald", 2);
	Bureaucrat *	Joe = new Bureaucrat("Joe", 10);
	Bureaucrat *	Miguel = new Bureaucrat("Miguel", 65);
	Intern *		nobody = new Intern();
	AForm *			shru = new ShrubberyCreationForm(Joe->getName());
	AForm *			robot = new RobotomyRequestForm(Donald->getName());
	AForm *			ppf = NULL;

	try {
		ppf = nobody->makeForm("presidentiaf pardon", Miguel->getName());
		robot->beSigned(*Miguel);
		shru->beSigned(*Joe);
		ppf->beSigned(*Joe);
		robot->execute(*Donald);
		shru->execute(*Donald);
		ppf->execute(*Donald);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;

	delete ppf;
	delete robot;
	delete shru;
	delete nobody;
	delete Miguel;
	delete Joe;
	delete Donald;
}

*/
