#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
class Character: public ICharacter {
    private:
        AMateria *materia[4];
        std::string name;
    public:
        Character();
        Character(const std::string &name);
        ~Character();
        Character(const Character &character);
        Character& operator=(const Character &character);
        const std::string& getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};
#endif