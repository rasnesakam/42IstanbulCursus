#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <limits.h>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const std::string& file){
    std::string line;
    std::ifstream streamIn(file);
    if (!streamIn.good())
    {
        std::cerr << file << ": Invalid file" << std::endl;
        return;
    }
    std::getline(streamIn, line);
    while (std::getline(streamIn, line)){
        size_t find = line.find(',');
        if (find != std::string::npos){
            std::string key = line.substr(0,find);
            std::string val = line.substr(find + 1, line.length());
            this->data[key] = std::stof(val);
        }
    }
    streamIn.close();
}
BitcoinExchange::BitcoinExchange(BitcoinExchange& oth){
    this->data = oth.data;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &oth){
    this->data = oth.data;
    return *this;
}

bool validateDate(const std::string &date){
    std::tm time;
	memset(&time, 0, sizeof(time));
    std::string yearString = date.substr(0,4);
    std::string monthString = date.substr(5,6);
    std::string dayString = date.substr(8,9);
    char *strEnd;
    int yearInt = std::strtol(yearString.c_str(), &strEnd, 10);
    if (strEnd == yearString.c_str()){
        return false;
	}
    int monthInt = std::strtol(monthString.c_str(), &strEnd, 10);
    if (strEnd == monthString.c_str()){
        return false;
	}
    int dayInt = std::strtol(dayString.c_str(), &strEnd, 10);
    if (strEnd == dayString.c_str()){
        return false;
	}
	time.tm_year = yearInt - 1900;
    time.tm_mon = monthInt - 1;
    time.tm_mday = dayInt;
    int ret = mktime(&time);
    return ret != -1;

}

void BitcoinExchange::btc(std::string& input){
    std::string line;
    std::ifstream streamIn(input);
    if (!streamIn.good())
    {
        std::cerr << input << ": Invalid file" << std::endl;
        return;
    }
    std::getline(streamIn, line);
    while (std::getline(streamIn, line)){
        size_t find = line.find('|');
        if (find != std::string::npos){
            std::string key = line.substr(0,find - 1);
            std::string val = line.substr(find+1, line.length());
            std::map<std::string, float>::iterator iterator_start = this->data.begin();
            std::map<std::string, float>::iterator iterator_end = this->data.end();
            while (iterator_start++ != iterator_end && iterator_start->first < key );
            if (iterator_start == iterator_end){
                std::cerr << "Error: No data found" << std::endl;
                return;
            }
			char *val_end;
			long double value = std::strtod(val.c_str(), &val_end);
			if ( !validateDate(key) || val.c_str() == val_end){
				std::cerr << "Error: bad input => " << key << std::endl;
				continue;
			}
			if (value < 0)
			{
				std::cerr << "Error: Not a positive number." << std::endl;
				continue;
			}
			if (value > INT_MAX){
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
            std::cout << key << " => " << iterator_start->second << " = " << iterator_start->second * value << std::endl;
            
        }
        else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
    }
    streamIn.close();
	return;
}
