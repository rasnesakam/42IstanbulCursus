#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include "Weapon.hpp"
class HumanA{
    private:
        Weapon Weapon;

    public:
        HumanA(std::string weaponType);
        void attack();
};

#endif