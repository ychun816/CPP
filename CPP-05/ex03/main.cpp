#include "AForm.hpp"
#include "Intern.hpp"
// #include "Bureaucrat.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

int main() 
{
    //create intern
    std::cout << "===== CREATE INTERN =====" << std::endl << std::endl;
    Intern intern;
    
    //test valid forms
    std::cout << "\n===== TEST Valid Forms =====" << std::endl;
    try 
    {
        //Shrubbery Creation Form
        std::cout << "\n🌲 [ shrubbery form ] 🌲" << std::endl;

        AForm& shrubberyForm = intern.makeForm("shrubbery creation", "CHOCO🍫");
        std::cout << "Created: " << shrubberyForm.getName() << std::endl;
        delete &shrubberyForm;// Remember to clean up!!!
        
        //Robotomy Request Form
        std::cout << "\n🤖 [ robotomy form ] 🤖" << std::endl;
        AForm& robotomyForm = intern.makeForm("robotomy request", "TEA🧋");
        std::cout << "Created: " << robotomyForm.getName() << std::endl;
        delete &robotomyForm;
        
        //Presidential Pardon Form
        std::cout << "\n🧑‍🦰 [ presidential form ] 🧑‍🦰" << std::endl;
        AForm& presidentialForm = intern.makeForm("presidential form", "LUIGI🍕");
        std::cout << "Created: " << presidentialForm.getName() << std::endl;
        delete &presidentialForm;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    //test invlaid form
    std::cout << "\n===== TEST Invalid Forms =====\n" << std::endl;
    try 
    {
        //wrong form name -> should throw exception
        std::cout << "[ Non-existent Form ]" << std::endl;
        AForm& invalidForm = intern.makeForm("FAKE FORM", "Target");
        std::cout << "Created: " << invalidForm.getName() << std::endl;
        delete &invalidForm;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error (expected): " << e.what() << std::endl;
    }

    //edge case
    std::cout << "\n===== TEST EDGE CASES =====\n" << std::endl;    
    try 
    {
        //empty form name
        std::cout << "[ Empty Name Form ] " << std::endl;
        AForm& emptyForm = intern.makeForm("", "Non porte ou");
        std::cout << "Created: " << emptyForm.getName() << std::endl;
        delete &emptyForm;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error (expected): " << e.what() << std::endl;
    }

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
