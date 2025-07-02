/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:47 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/02 16:47:23 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
#define SERIALIZER_CLASS_HPP
#include <iostream>
#include "Data.hpp"

class Serializer
{
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

private:
    Serializer();
    Serializer(const Serializer &src);
    Serializer &operator=(const Serializer &rhs);
    ~Serializer();
};

#endif