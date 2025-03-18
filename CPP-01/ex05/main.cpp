#include "Harl.hpp"

//The goal of this exercise is to use pointers to member functions
//Harl has to complain without using a forest of if/else if/else.
//Create and turn in tests to show that Harl complains a lot.

int main()
{
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain(" TRYING INVALID HARL??"); // Should print "Invalid level"
}