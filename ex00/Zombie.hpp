#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        void anounce(void);
};


void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif