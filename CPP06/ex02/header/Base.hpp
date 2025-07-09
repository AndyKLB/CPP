/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:28:24 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/09 15:18:03 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP_CLASS
#define BASE_HPP_CLASS
#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
    virtual ~Base(){}; // afin de generer le RTTI pour le dynamic cast
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

class D : public Base // test invalid base class dans le main
{
};

#endif