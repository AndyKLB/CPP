/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:56:21 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/02 17:06:25 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_CLASS_HPP
#define SCALAR_CONVERTER_CLASS_HPP
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter
{
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter();
    ScalarConverter(const std::string &src);
    ScalarConverter &operator=(const std::string &rhs);
    ~ScalarConverter();

    static bool isChar(const std::string & literal);
    static bool isInt(const std::string & literal);
    static bool isFloat(const std::string & literal);
    static bool isDouble(const std::string & literal);
    static bool isPseudo(const std::string & literal, double &value);

    static void printChar(const double res);
    static void printInt(const double res);
    static void printFloat(const double res);
    static void printDouble(const double res);
};

#endif