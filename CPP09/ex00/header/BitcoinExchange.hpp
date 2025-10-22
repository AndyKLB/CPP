/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:59:46 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/22 14:48:17 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_CLASS_HPP
#define BTC_CLASS_HPP

#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>

class BitcoinExchange
{
public:
    BitcoinExchange(std::ifstream &dataFileCsv);
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange();

    void printInputFile(std::string &date, float value) const;

private:
    static bool isValidDate(const std::string &date);
    static bool isValidValue(float value);
    BitcoinExchange();
    std::map<std::string, float> _dataFile;
};

#endif`