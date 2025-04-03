#include <ctime> //for srand and time

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//You cannot create an object of an abstract class (AForm)
//You must use a concrete subclass that implements all pure virtual functions.
// int main()
// {
//     try
//     {
//         std::cout << "==== Create a Person A ====" << std::endl;
//         Bureaucrat validPerson("BOB", 10);
//         ShrubberyCreationForm treeForm("TREE FORM");//signable , executable
//         std::cout <<  treeForm << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }




//     return 0;
// }

/*test ref*/
int main() 
{
	srand(time(0));

	try {
		Bureaucrat lawyer("The Lawyer", 30);        // High rank (30), can sign and execute all forms
		Bureaucrat bartleby("Bartleby", 140);       // Lower rank, can only sign Shrubbery form
		Bureaucrat scrivener("The Scrivener", 150); // Lowest rank, cannot sign or execute any form
		std::cout << std::endl << "--------------------------"<< std::endl;

		// Testing with ShrubberyCreationForm
		ShrubberyCreationForm shrubbery("home");
		std::cout << std::endl;

		try 
        {
			lawyer.signForm(shrubbery);      // "The Lawyer" signs Shrubbery form
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		try 
        {
			lawyer.executeForm(shrubbery);   // "The Lawyer" executes Shrubbery form
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

		try 
        {
			bartleby.signForm(shrubbery);    // "Bartleby" attempts to sign Shrubbery form (succeeds)
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		try 
        {
			bartleby.executeForm(shrubbery); // "Bartleby" attempts to execute Shrubbery form (fails, low rank)
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

		try 
        {
			scrivener.signForm(shrubbery);   // "The Scrivener" attempts to sign Shrubbery form (fails)
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		// try 
        // {
        //     if (_target.empty())
        //     {
        //         throw std::invalid_argument("Target name cannot be empty");
        //         scrivener.executeForm(shrubbery);// "The Scrivener" attempts to execute Shrubbery form (fails)
        //     } 
		// } catch (const std::exception& e) 
        // {
		// 	std::cerr << e.what() << std::endl;
		// }
		std::cout << std::endl << "--------------------------"<< std::endl;

		// Testing with RobotomyRequestForm
		RobotomyRequestForm robotomy("Bartleby");

		try 
        {
			lawyer.signForm(robotomy);       // "The Lawyer" signs Robotomy form
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		try 
        {
			lawyer.executeForm(robotomy);    // "The Lawyer" executes Robotomy form
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

		try 
        {
			bartleby.signForm(robotomy);     // "Bartleby" attempts to sign Robotomy form (fails)
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

		try 
        {
			scrivener.executeForm(robotomy); // "The Scrivener" attempts to execute Robotomy form (fails)
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl << "--------------------------"<< std::endl;

		// Testing with PresidentialPardonForm
		PresidentialPardonForm pardon("The Scrivener");
		std::cout << std::endl;

		try 
        {
			lawyer.signForm(pardon);         // "The Lawyer" signs Pardon form
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		try 
        {
			lawyer.executeForm(pardon);      // "The Lawyer" executes Pardon form
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

		try 
        {
			bartleby.executeForm(pardon);    // "Bartleby" attempts to execute Pardon form (fails, low rank)
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		try 
        {
			scrivener.signForm(pardon);      // "The Scrivener" attempts to sign Pardon form (fails)
		} catch (const std::exception& e) 
        {
			std::cerr << e.what() << std::endl;
		}
	}
	catch (const std::exception& e) 
    {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}
	return (0);
}