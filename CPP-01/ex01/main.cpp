#include "Zombie.hpp"

int main()
{
    int nb_zombies = 10;
    std::string name;

    std::cout << "🧟 ZOMBIE ARMY ALERTTT!🧟" << std::endl;
    std::cout << "📢 NAME UR ZOMBIE ARMY: ";
    std::getline(std::cin, name);
	if (name.empty() || name[0] == ' ')
		std::cout << "ERROR : U GOT NO NAME FOR THEM? THEY LEFT AND THEY R SO SAD :(" << std::endl;
	else
	{
    	Zombie* horde_heap = zombieHorde(nb_zombies, name);
    	// Delete the entire horde (important to use delete[] for arrays)
    	delete[] horde_heap;
	}
    return 0;
}