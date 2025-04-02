#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

/**
 * @note
 * References: are aliases and cannot be null.
 * Pointers : can be null and can be changed to point to something else.
 * @note std::string getType() const;
 * -> Use const references to prevent unnecessary copies
 */
class Weapon
{
    public:
    Weapon(std::string weaponName);
    ~Weapon();

    void setType(std::string weaponType);
    std::string getType() const;

    private:
        std::string _weaponName;
};

#endif

/**Extra Compile Notes:
 * 
 * @note #pragma once
 * ✔ prevent multiple inclusions of a header file.
 * ✔ Less code – No need for #ifndef and #define.
 * ✔ Less chance of naming conflicts – No need to create unique macro names.
 * ✔ Faster compilation – Modern compilers optimize #pragma once better than include guards.
*/