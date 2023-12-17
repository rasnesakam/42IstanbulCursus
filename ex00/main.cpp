#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: too many argument!" << std::endl;
		return 0;
	}

	try
	{
		BitcoinExchange bitcoinExchange(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
