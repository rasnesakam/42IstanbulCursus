#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP
#include "AMateria.hpp"

class ICharacter{

    public:
        virtual ~ICharacter();
        virtual const std::string& getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};

#endif