#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& Filecsv)
    : m_prices(new std::map<std::string, double>())
{
    std::ifstream bitcoinFile(Filecsv.c_str());
    if (bitcoinFile.fail())
	{
        throw std::runtime_error( "Error: Failed to open " + Filecsv);
    }
    std::string line;
    std::getline(bitcoinFile, line);
    while (std::getline(bitcoinFile, line))
	{
        std::istringstream ss(line);
        std::string dateStr;
        double price;
        std::getline(ss, dateStr, ',');
        ss >> price;
        (*m_prices)[dateStr] = price;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rs)
    : m_prices(new std::map<std::string, double>())
{
    copy(rs);
}

BitcoinExchange::~BitcoinExchange()
{
    clear();
    delete m_prices;
	std::cout <<  "Destructor called";
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rs)
{
    if (this != &rs)
	{
        clear();
        copy(rs);
    }
    return *this;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = m_prices->find(date);
    if (it == m_prices->end())
	{
        std::map<std::string, double>::const_iterator lower_it = m_prices->lower_bound(date);
        if (lower_it == m_prices->begin())
		{
            throw std::runtime_error( "Error: Bitcoin was not created yet on this date");
        } else {
            --lower_it;
            return lower_it->second;
        }
    } else
	{
        return it->second;
    }
}

void BitcoinExchange::copy(const BitcoinExchange& rs)
{
    *m_prices = *rs.m_prices;
}

void BitcoinExchange::clear()
{
    m_prices->clear();
}
