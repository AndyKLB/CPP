/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:24:59 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/31 15:08:01 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_CLASS_HPP
#define MUTANT_STACK_CLASS_HPP

#include <stack>
#include <list>
#include <iostream>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack &src);
    MutantStack &operator=(const MutantStack &rhs);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"
#endif