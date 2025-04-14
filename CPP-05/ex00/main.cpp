#include "Bureaucrat.hpp"

//RULES
//A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade)
//since grade 1 is the highest and 150 the lowest,
//incrementing a grade 3 should result in a grade 2 for the bureaucrat.

////test static funcs
static void	testCreateBureaucrat(std::string name, int grade)
{
	try
	{
		std::cout << "Creating Bureaucrat: " << std::endl <<
					 "Name: " << name << std::endl <<
					 "Grade: " << grade << std::endl;
		Bureaucrat	test(name, grade);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat created successfully" << std::endl;
	return;
}

static void	testIncrement(std::string name, unsigned int grade)
{
	Bureaucrat	test(name, grade);

	std::cout << test << std::endl;
	try
	{
		test.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat's grade incremented successfully" << std::endl;
	std::cout << test << std::endl;
	return;
}

static void	testDecrement(std::string name, unsigned int grade)
{
	Bureaucrat	test(name, grade);

	std::cout << test << std::endl;
	try
	{
		test.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat's grade decremented successfully" << std::endl;
	std::cout << test << std::endl;
	return;
}

int	main(void)
{
    std::cout << "\n=== CREATE BUREAUCRAT ====" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
	testCreateBureaucrat("STAFF1🧛", -1);
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	testCreateBureaucrat("STAFF2👦", 10);
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	testCreateBureaucrat("STAFF3🧟", 150);
	std::cout << "-----------------------------------------------------------------------" << std::endl;

    std:: cout << "\n\n𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊 𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼" << std::endl<< std::endl;
    std::cout << "\n==== TEST INCREMENT GRADE ====" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	testIncrement("STAFF4👼", 5);
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	testIncrement("STAFF5🦸", 1);
	std::cout << "-----------------------------------------------------------------------" << std::endl;

    std:: cout << "\n\n𓇼 ⋆.˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ˚ 𓆉 𓆝 " << std::endl << std::endl;
    std::cout << "\n==== TEST DECREMENT GRADE ====" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	testDecrement("STAFF6🧙", 149);
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	testDecrement("STAFF7🧟", 150);
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	return 0;
}


/*OG, CHECK LATER
int main()
{

    //
    std:: cout << std::endl;
    try
    {
        std::cout << "======== Create Valid Person (10) ========" << std::endl;
        Bureaucrat validPerson("VALID🥷", 10);//init with name and grade
        std::cout << validPerson << std::endl;

        std::cout << "===== decrement by 1 (nb goes higher by 1) =====" << std::endl;
        validPerson.decrementGrade();
        std::cout << validPerson << std::endl;

        std::cout << "===== increment by 2 (nb goes lower by 2) =====" << std::endl;
        validPerson.incrementGrade();
		validPerson.incrementGrade();
        std::cout << validPerson << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    //too high -> 1 
    std:: cout << "\n\n𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊𖡼𖤣𖥧𖡼𓋼𖤣𖥧𓋼𓍊" << std::endl<< std::endl;
    try
    {
        std::cout << "======== Create High Person (-1) ========" << std::endl;
        Bureaucrat highPerson("HIGH🦸", -1);//init with name and grade
        std::cout << highPerson << std::endl;

        std::cout << "===== decrement by 1 (nb goes higher by 1) =====" << std::endl;
        highPerson.decrementGrade();
        std::cout << highPerson << std::endl;

        std::cout << "===== increment by 2 (nb goes lower by 2) =====" << std::endl;
        highPerson.incrementGrade();
		highPerson.incrementGrade();//
        std::cout << highPerson << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    //too low -> 150
    std:: cout << "\n\n𓇼 ⋆.˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ˚ 𓆉 𓆝 𓆡⋆.˚ 𓇼 ˚ 𓆉 𓆝 " << std::endl << std::endl;
    try
    {
        std::cout << "======== Create Low Person (150) ========" << std::endl;
        Bureaucrat lowPerson("LOW🧟", 150);//init with name and grade
        std::cout << lowPerson << std::endl;

        std::cout << "===== decrement by 1 (nb goes higher by 1) =====" << std::endl;
        lowPerson.decrementGrade();
        std::cout << lowPerson << std::endl;

        std::cout << "==== increment by 2 (nb goes lower by 2) ====" << std::endl;
        lowPerson.incrementGrade();
		lowPerson.incrementGrade();
        std::cout << lowPerson << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
*/

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