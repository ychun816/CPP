#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
   {
        Weapon club = Weapon("crude spiked club");
      
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        
        HumanB jim("Jim");
        jim.attack();//for test-> no weapon!!
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    } 
    return 0;
}

//  Weapon club = Weapon("crude spiked club");//for test
//  club.attack();//for test
//  club.setType("just club");//for test
//  club.attack();//for test
