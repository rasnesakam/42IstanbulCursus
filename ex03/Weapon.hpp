#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(void);
        Weapon(std::string type);
        void setType(std::string type);
        const std::string& getType();
};

#endif