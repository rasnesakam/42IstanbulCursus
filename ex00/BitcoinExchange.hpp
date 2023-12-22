#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map <std::string, float> data;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &file);
        BitcoinExchange(BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &oth);
        void btc(std::string& input);
};

#endif
