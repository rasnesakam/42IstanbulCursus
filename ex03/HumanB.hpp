#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
#include "Weapon.hpp"
class HumanB{
    private:
        Weapon *weapon;
        std::string name;
    public:
        HumanB(void);
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &weapon);
        void attack();
};


#endif