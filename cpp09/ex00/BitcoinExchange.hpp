#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <stdexcept>
# include <fstream>
# include <sstream>
# include <iostream>

class BitcoinExchange
{

	public:
		BitcoinExchange(const std::string& Filecsv);
		BitcoinExchange(const BitcoinExchange& rs);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& rs);
		double getExchangeRate(const std::string& date) const;

	private:
		std::map<std::string, double>* m_prices;
		void copy(const BitcoinExchange& rs);
		void clear();

};

#endif
