/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:46:55 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/31 13:26:48 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_HPP
#define RPN_CLASS_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <stack>
#include <climits>
#include <sstream>
#include <cstdlib>

class RPN
{
public:
    RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &rhs);
    ~RPN();
    int rpnCalcul(const std::string & expression);

private:
    std::stack<long long> _stack;
    bool isNumber(const std::string & token) const;
    bool isOperator(const std::string & token) const;
    int applyCalcul(const std::string & ope, long long a, long long b);
};

#endif