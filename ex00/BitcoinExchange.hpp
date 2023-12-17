#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <ctime>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, long double> data;
        std::map<std::string, long double> validDates;
        
        time_t firstDate;
        time_t lastDate;

		std::string strDate;
		std::string strValue;

        std::map<std::string, long double> readData(const char* fileName);
        long double dateFinder(std::string value);
        void setFirstDate();
        void setLastDate();
        void setValidDates();

        bool errorHandling(const std::string &line, int i);
    public:
        BitcoinExchange();
        BitcoinExchange(const char *fileName);
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange &operator = (const BitcoinExchange&);
        ~BitcoinExchange();

};

#endif
