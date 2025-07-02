/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:16 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/02 16:46:51 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Serializer.hpp"

Serializer::Serializer()
{
}
Serializer::Serializer(const Serializer &src)
{
    (void) src;
}
Serializer &Serializer::operator=(const Serializer &rhs)
{
    (void) rhs;
    return (*this);
}
Serializer::~Serializer()
{
}
uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}