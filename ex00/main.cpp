#include "easyfind.hpp"
#include <vector>
int main(){
	int val = 5;
	std::vector<int> my_vec;
	my_vec.push_back(0);
	my_vec.push_back(1);
	my_vec.push_back(2);
	my_vec.push_back(3);
	my_vec.push_back(5);
	
	std::cout << easyfind(my_vec,val);
}