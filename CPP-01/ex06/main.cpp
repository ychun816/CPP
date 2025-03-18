#include "Harl.hpp"

//Filter messages so only relevant ones are displayed.
//will obmit the msg above the index!
int main(int ac, char *av[])
{
    Harl harl;

    if (ac < 2)
    {
        cout << "Error: No valid input. Please Enter 1 Filter Message." << endl;//display all?
        return 1;
    }
    string input = av[1];
    harl.filterComplains(input);
    return 0;
}