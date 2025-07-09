/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:05:38 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/07 14:40:37 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const std::string &src)
{
    (void)src;
}
ScalarConverter &ScalarConverter::operator=(const std::string &rhs)
{
    (void)rhs;
    return (*this);
}
ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &literal)
{
    double res;
    char *pEnd;

    if (isPseudo(literal, res))
        ;
    else if (isChar(literal))
        res = static_cast<double>(literal[0]);
    else if (isInt(literal))
        res = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        res = static_cast<double>(std::strtof(literal.c_str(), &pEnd));
    else if (isDouble(literal))
        res = static_cast<double>(std::strtod(literal.c_str(), &pEnd));
    else
    {
        std::cout << "invalid input" << std::endl;
        return;
    }
    printChar(res);
    printInt(res);
    printFloat(res);
    printDouble(res);
}

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.empty())
        return (false);
    return (literal.length() == 1 && !isdigit(literal[0]) && isprint(literal[0]));
}
bool ScalarConverter::isInt(const std::string &literal)
{
    char *pEnd;
    if (literal.empty())
        return (false);
    long nb = std::strtol(literal.c_str(), &pEnd, 10);
    if (!*pEnd && nb <= std::numeric_limits<int>::max() && nb >= std::numeric_limits<int>::min())
        return (true);
    return (false);
}
bool ScalarConverter::isFloat(const std::string &literal)
{
    std::string cutNbr;
    char *pEnd;

    if (literal.empty() || literal.back() != 'f') // verifie chaine vide et le 'f' a la fin
        return (false);
    if (literal.find('.') == std::string::npos) // verifie la presence d un point
        return (false);
    cutNbr = literal.substr(0, literal.size() - 1); // enleve le 'f' pour tenter une conversion
    std::strtof(cutNbr.c_str(), &pEnd);             // convertit en float
    if (*pEnd == '\0')                              // verifie que toute la chaine a ete consommee
        return (true);
    return (false);
}
bool ScalarConverter::isDouble(const std::string &literal)
{
    char *pEnd;

    if (literal.empty() || literal.find('f') != std::string::npos)
        return (false);
    if (literal.find('.') == std::string::npos)
        return (false);
    std::strtod(literal.c_str(), &pEnd);
    if (*pEnd == '\0')
        return (true);
    return (false);
}

bool ScalarConverter::isPseudo(const std::string &literal, double &res)
{
    if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
        res = std::numeric_limits<double>::infinity();
    else if (literal == "-inf" || literal == "-inff")
        res = -std::numeric_limits<double>::infinity();
    else if (literal == "nan" || literal == "nanf")
        res = std::numeric_limits<double>::quiet_NaN();
    else
        return (false);
    return (true);
}

void ScalarConverter::printChar(const double res)
{
    std::cout << "char: ";
    if (std::isnan(res) || res < std::numeric_limits<char>::min() || res > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(res)))
        std::cout << "non displayable" << std::endl;
    else
        std::cout << static_cast<char>(res) << std::endl;
}
void ScalarConverter::printInt(const double res)
{
    std::cout << "int: ";
    if (std::isnan(res) || res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(res) << std::endl;
}
void ScalarConverter::printFloat(const double res)
{
    std::cout << "float: " << static_cast<float>(res);
    if (res == static_cast<int>(res))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
}
void ScalarConverter::printDouble(const double res)
{
    std::cout << "double: " << res;
    if (res == static_cast<int>(res))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}