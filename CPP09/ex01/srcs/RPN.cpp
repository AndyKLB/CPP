/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:47:04 by ankammer          #+#    #+#             */
/*   Updated: 2025/10/23 13:14:55 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RPN.hpp"

RPN::RPN()
{
}
RPN::RPN(const RPN &src) : _stack(src._stack)
{
}
RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
        _stack = rhs._stack;
    return (*this);
}
RPN::~RPN()
{
}

int RPN::rpnCalcul(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        if (isNumber(token))
            _stack.push(std::atoll(token.c_str()));
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw(std::logic_error("Error: not enough operands"));
            long long b = _stack.top();
            _stack.pop();
            long long a = _stack.top();
            _stack.pop();
            long long result = applyCalcul(token, a, b);

            _stack.push(result);
        }
        else
            throw(std::logic_error("Error: invalid token"));
    }
    if (_stack.size() != 1)
        throw(std::logic_error("Error: invalid expression"));
    return (_stack.top());
}

bool RPN::isNumber(const std::string &token) const
{
    return (token.length() == 1 && isdigit(token[0]));
}

bool RPN::isOperator(const std::string &token) const
{
    return (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

int RPN::applyCalcul(const std::string &ope, long long a, long long b)
{
    long long res = 0;
    if (ope == "+")
        res = a + b;
    else if (ope == "-")
        res = a - b;
    else if (ope == "*")
        res = a * b;
    else if (ope == "/")
    {
        if (b == 0)
            throw(std::logic_error("Error: division by zero"));
        res = a / b;
    }
    if (res > INT_MAX || res < INT_MIN)
        throw(std::overflow_error("Error: result overflow"));
    return (res);
}
