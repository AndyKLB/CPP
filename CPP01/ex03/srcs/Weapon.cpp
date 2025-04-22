/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:14 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/22 13:57:23 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
    std::cout << _type << " destroyed" << std::endl;
}

std::string const &Weapon::getRefType() const
{
    std::string const &refType = _type;
    return (refType);
}

void Weapon::setType(std::string newType)
{
    _type = newType;
}