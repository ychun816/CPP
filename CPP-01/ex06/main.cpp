#include "Harl.hpp"

//Filter messages so only relevant ones are displayed.
//will obmit the msg above the index!
int main(int ac, char *av[])
{
    Harl harl;
    string input = av[1];
    
    if (ac == 2)
    {
        harl.filterComplains(input);
    }
    else//filter according to input av[1]
        cout << "Error: Please Enter 1 Filter Index or Msg" << endl;//display all?

    return 0;
}