#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

bool BitcoinExchange::errorHandling(const std::string &line, int i)
{
	if (!line.compare("date | value") && i == 0)
		return false;

	if (line.find("|") == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	size_t pipePosition = line.find("|");
	size_t lastDashPosition = line.find_first_of("-");
	size_t firstDashPosition = line.find_last_of("-");

	if (lastDashPosition == firstDashPosition ||
		lastDashPosition == std::string::npos ||
		firstDashPosition == std::string::npos )
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	if (lastDashPosition + 4 == pipePosition)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	if (pipePosition == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	strDate = line.substr(0, pipePosition - 1);

	if (pipePosition >= line.length() - 1)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	
	strValue = line.substr(pipePosition + 2, line.length());

	if (std::strtod(strValue.c_str(), NULL) > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	if (std::atoi(strValue.c_str()) < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	if (strValue.empty())
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	if (dateFinder(strDate) == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	return true;
}

BitcoinExchange::BitcoinExchange(const char *fileName)
{
	data = readData("data.csv");
	std::fstream inputFile(fileName, std::ios::in);
	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	
	setFirstDate();
	setLastDate();
	setValidDates();

	int i = 0;
	std::string line;

	while (std::getline(inputFile, line))
	{
		if (!errorHandling(line, i))
			continue;

		double val = std::strtod(strValue.c_str(), NULL);
		std::cout << strDate;
		std::cout << " => ";
		std::cout << strValue;
		std::cout << " = ";
		std::cout << dateFinder(strDate) * val;
		std::cout << std::endl;

		i++;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange&)
{
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	data.clear();
}

std::map<std::string, long double> BitcoinExchange::readData(const char *fileName)
{
	std::fstream inputFile(fileName, std::ios::in);
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open the data file.");

	std::map<std::string, long double> data;

	std::string line;

	int i = 0;
	while (std::getline(inputFile, line))
	{
		if (!line.compare("date,exchange_rate") && i == 0)
			continue;
		std::string strDate;
		std::string strValue;

		size_t posSpace = line.find(",");

		strDate = line.substr(0, posSpace);
		strValue = line.substr(posSpace + 1, line.length());

		char *end;
		data.insert(std::pair<std::string, long double>(strDate, std::strtod(strValue.c_str(), &end)));
		i++;
	}

	inputFile.close();
	return data;
}

long double BitcoinExchange::dateFinder(std::string value)
{
	std::map<std::string, long double>::iterator it_data = data.find(value);
	std::map<std::string, long double>::iterator it_validDates = validDates.find(value);

	if (it_validDates == validDates.end())
		return std::string::npos;

	if (it_data == data.end())
	{
		int currentYear = std::atoi(value.substr(0, 4).c_str());
		int currentMonth = std::atoi(value.substr(5, 2).c_str());
		int currentDay = std::atoi(value.substr(8, 2).c_str());
		std::tm currentTime;
		std::memset(&currentTime, 0, sizeof(currentTime));
		currentTime.tm_year = currentYear - 1900;
		currentTime.tm_mon = currentMonth - 1;
		currentTime.tm_mday = currentDay;
		time_t ct = mktime(&currentTime);

		ct -= (24 * 60 * 60);
		std::tm *convertedTime = localtime(&ct);
		char result_str[11];
		strftime(result_str, sizeof(result_str), "%Y-%m-%d", convertedTime);

		return dateFinder(result_str);
	}

	return it_data->second;
}

void BitcoinExchange::setFirstDate()
{
	std::string firstDateStr = data.begin()->first;
	std::tm firstTime;
	std::memset(&firstTime, 0, sizeof(firstTime));

	int firstYear = std::atoi(firstDateStr.substr(0, 4).c_str());
	int firstMonth = std::atoi(firstDateStr.substr(5, 2).c_str());
	int firstDay = std::atoi(firstDateStr.substr(8, 2).c_str());
	firstTime.tm_year = firstYear - 1900;
	firstTime.tm_mon = firstMonth - 1;
	firstTime.tm_mday = firstDay;
	
	firstDate = mktime(&firstTime);
}

void BitcoinExchange::setLastDate()
{
	std::string lastDateStr = (--data.end())->first;
	std::tm lastTime;
	std::memset(&lastTime, 0, sizeof(lastTime));
	
	int lastYear = std::atoi(lastDateStr.substr(0, 4).c_str());
	int lastMonth = std::atoi(lastDateStr.substr(5, 2).c_str());
	int lastDay = std::atoi(lastDateStr.substr(8, 2).c_str());
	lastTime.tm_year = lastYear - 1900;
	lastTime.tm_mon = lastMonth - 1;
	lastTime.tm_mday = lastDay + 1;

	lastDate = mktime(&lastTime);
}

void BitcoinExchange::setValidDates()
{
	time_t currentDate = firstDate;

	std::tm convertedTime = *localtime(&currentDate);
	while (currentDate <= lastDate)
	{
		char result_str[11];
		convertedTime = *localtime(&currentDate);
		strftime(result_str, sizeof(result_str), "%Y-%m-%d", &convertedTime);
		validDates.insert(std::pair<std::string, long double>(result_str, 0));
		currentDate += 86400;
	}
}
