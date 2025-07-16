/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:43:31 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/16 16:02:55 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T, typename F>
void iter(const T *array, std::size_t size, F function)
{
    if (!array)
        return;
    for (std::size_t i = 0; i < size; i++)
        function(array[i]);
    std::cout << std::endl;
}

template <typename T>
void printArray(const T &array)
{
    std::cout << array << " ";
}

template <typename T>
void printArrayMore(const T &array)
{
    static int i = 0;
    std::cout << "[" << i << "] = ";
    std::cout << array  << std::endl;
    i++;
}

#endif