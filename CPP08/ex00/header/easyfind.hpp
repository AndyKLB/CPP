/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:17:00 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/23 12:07:55 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>
#include <list>
#include <deque>
#include <vector>

template <typename T>
typename T::const_iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif