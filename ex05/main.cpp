#include "Harl.hpp"

int main(){

	Harl h;
	h.complain("ERROR");
	h.complain("DEBUG");
	h.complain("WARNING");
	h.complain("INFO");
	h.complain("VERBOSE");
	return 0;
}