/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:05:38 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/01 16:21:37 by ankammer         ###   ########.fr       */
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
    cutNbr = literal.substr(0, literal.size() - 1); // enleve le 'f' pour tenter une conversio
    std::strtof(cutNbr.c_str(), &pEnd);             // convertit en float
    if (*pEnd == '\0')                              // verifie que toute la chaine a ete consomee
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