/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:59:49 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/30 13:21:42 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/BitcoinExchange.hpp"
#include <string>

BitcoinExchange::BitcoinExchange(std::ifstream &dataFileCsv)
{
    std::string buf;
    std::string date;
    std::string strRate;
    std::getline(dataFileCsv, buf);
    while (getline(dataFileCsv, buf))
    {
        size_t separator = buf.find(',');
        if (separator == std::string::npos)
            continue;
        date = buf.substr(0, separator);
        strRate = buf.substr(separator + 1);
        std::istringstream iss(strRate);
        float floatRate;
        iss >> floatRate;
        if (!iss.fail() && iss.eof())
            _dataFile[date] = floatRate;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _dataFile(src._dataFile)
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
        _dataFile = rhs._dataFile;
    return (*this);
}

void BitcoinExchange::printInputFile(std::string &date, float value) const
{

    if (!isValidDate(date))
        return;
    if (!isValidValue(value))
        return;
    std::map<std::string, float>::const_iterator rateIt = _dataFile.lower_bound(date);
    if (rateIt == _dataFile.begin() && rateIt->first != date)
    {
        std::cerr << "Error: no data available before this date" << std::endl;
        return;
    }
    else if (rateIt == _dataFile.end() || rateIt->first != date)
        rateIt--;
    std::cout << date << " => " << value << " = " << (value * rateIt->second) << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return (false);
    }
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return (false);
        }
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if ((month < 1 || month > 12) || day < 1)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return (false);
    }
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDays[1] = 29;
    if (day > monthDays[month - 1])
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return (false);
    }
    return true;
}
bool BitcoinExchange::isValidValue(float value)
{
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }
    else if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    return (true);
}

BitcoinExchange::~BitcoinExchange()
{
}