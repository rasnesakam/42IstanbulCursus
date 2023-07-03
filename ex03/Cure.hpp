#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure: public AMateria{

    public:
        Cure();
        ~Cure();
        Cure(const Cure &cure);
        Cure &operator=(const Cure &cure);
        AMateria *clone() const;
        void use(ICharacter &character);
};

#endif