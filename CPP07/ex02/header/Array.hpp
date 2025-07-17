/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:50:01 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/17 11:38:18 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
#define ARRAY_CLASS_HPP
#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int n);
    Array(const Array &src);
    ~Array();

    unsigned int size() const;
    const T *getArrayAdress() const;
    
    Array &operator=(const Array &rhs);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

private:
    T *_array;
    unsigned int _size;
};
#include "Array.tpp"
#endif