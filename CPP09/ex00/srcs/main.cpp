/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:00:07 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/30 12:27:37 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    std::ifstream dataFile("assets/data.csv");
    if (!dataFile)
    {
        std::cerr << "Error opening DataFile.csv" << std::endl;
        return (1);
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << "Error opening InputFile" << std::endl;
        return (1);
    }
    BitcoinExchange btc(dataFile);
    std::string buf;
    std::getline(inputFile, buf);
    while (std::getline(inputFile, buf))
    {
        std::size_t separator = buf.find('|');
        if (separator == std::string::npos)
        {
            std::cout << "Error: bad input => " << buf << std::endl;
            continue;
        }
        std::string date = buf.substr(0, separator - 1);
        std::string strValue = buf.substr(separator + 1);
        std::istringstream iss(strValue);
        float value;
        iss >> value;
        if (iss.fail() && !iss.eof())
        {
            std::cerr << "Error: isstringstream" << std::endl;
            continue;
        }
        btc.printInputFile(date, value);
    }
}