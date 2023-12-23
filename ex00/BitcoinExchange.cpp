#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <limits.h>
#include <regex>
#include <chrono>


using std::chrono::system_clock;

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
	
	std::regex datePattern("^\\d{4}-\\d{2}-\\d{2}$");
	if (!std::regex_match(date,datePattern))
		return false;

    std::string yearString = date.substr(0,4);
    std::string monthString = date.substr(5,2);
    std::string dayString = date.substr(8,2);
    char *strEnd;

    int yearInt = std::strtol(yearString.c_str(), &strEnd, 10);
    if (strEnd == yearString.c_str() || yearInt < 1900){
        return false;
	}
    int monthInt = std::strtol(monthString.c_str(), &strEnd, 10);
    if (strEnd == monthString.c_str() || monthInt < 1 || monthInt > 12){
        return false;
	}
    int dayInt = std::strtol(dayString.c_str(), &strEnd, 10);
    if (strEnd == dayString.c_str() || dayInt < 1 || dayInt > 31){
        return false;
	}
	time.tm_year = yearInt - 1900;
    time.tm_mon = monthInt - 1;
    time.tm_mday = dayInt;

	system_clock::time_point tp = system_clock::from_time_t(std::mktime(&time));
	time_t timeAsTimeT = std::chrono::system_clock::to_time_t(tp);
	std::tm result = *std::localtime(&timeAsTimeT);
	return result.tm_year == time.tm_year && result.tm_mon == time.tm_mon && result.tm_mday == time.tm_mday;
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
			double db_value;
            std::map<std::string, double>::iterator iterator_start = this->data.begin();
            std::map<std::string, double>::iterator iterator_end = this->data.end();
            if (this->data.find(key) == iterator_end)
			{
				std::map<std::string, double>::iterator iterator_found = this->data.end();
				while (iterator_start != iterator_end){
					if (iterator_start->first < key)
						iterator_found = iterator_start;
					iterator_start++;
				}
				if (iterator_found == iterator_end){
					std::cerr << "Error: No data found. => " << key << std::endl;
					continue;
				}
				db_value = iterator_found->second;
			}
			else
				db_value = this->data[key];
			
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
			if (value > 1000){
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
            std::cout << key << " => " << db_value << " = " << db_value * value << std::endl;
            
        }
        else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
    }
    streamIn.close();
	return;
}
