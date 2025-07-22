/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:11:45 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/22 14:36:40 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <iostream>
#include <iterator>
#include <vector>    // pour stocker les entiers
#include <algorithm> // pour std::sort(), std::min_element(), etc.
#include <stdexcept> // pour std::exception, std::out_of_range

class Span
{
public:
    Span(unsigned int N);
    Span(const Span &src);
    Span &operator=(const Span &rhs);

    void addNumber(int number);
    void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
    int shortestSpan();
    int longestSpan();

private:
    Span();
    unsigned int _sizeMax;
    std::vector<int> _vec;
};

#endif