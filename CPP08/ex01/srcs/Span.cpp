/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:24:19 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/22 15:03:17 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

Span::Span(unsigned int N) : _sizeMax(N)
{
}
Span::Span(const Span &src) : _sizeMax(src._sizeMax), _vec(src._vec)
{
}
Span &Span::operator=(const Span &rhs)
{

    if (this != &rhs)
    {
        this->_sizeMax = rhs._sizeMax;
        this->_vec = rhs._vec;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_vec.size() >= _sizeMax)
        throw std::out_of_range("Out of range: vector is already full");
    _vec.push_back(number);
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    if ((_vec.size() + std::distance(begin, end)) > _sizeMax)
        throw std::out_of_range("Out of range: vector is too small for this range");
    for (; begin < end; begin++)
        _vec.push_back(*begin);        
}

int Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw std::logic_error("Logic_error: less than 2 elements, no span possible");
    std::vector<int> tmp(_vec);
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (unsigned long i = 1; i < tmp.size(); i++)
        if ((tmp[i] - tmp[i - 1]) < shortest)
            shortest = (tmp[i] - tmp[i - 1]);
    return shortest;
}
int Span::longestSpan()
{
    if (_vec.size() < 2)
        throw std::logic_error("Logic_error: less than 2 elements, no span possible");
    int max = *std::max_element(_vec.begin(), _vec.end());
    int min = *std::min_element(_vec.begin(), _vec.end());
    return (max - min);
}