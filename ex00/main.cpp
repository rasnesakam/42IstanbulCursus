#include "Zombie.hpp"

int main(void){
	Zombie *z = newZombie("Ahmet");
    z->anounce();
	delete(z);
    randomChump("alicenap");
}