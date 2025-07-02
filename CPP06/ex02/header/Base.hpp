/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:28:24 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/02 17:32:49 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP_CLASS
#define BASE_HPP_CLASS

class Base
{
public:
    virtual ~Base();
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

class D : public Base
{
};

#endif