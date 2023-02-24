#include "Zombie.hpp"

int main (void){

    Zombie *zombies = zombieHorde(8,"alicenap");
    for (int i = 0; i < 8; i++){
        zombies[i].anounce();
        
    }
    return 0;
}