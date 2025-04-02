#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    // TEST FOR INVALID -> Should print "Invalid level"
    harl.complain(" TRYING INVALID HARL??");
}