/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:34 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 17:11:34 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/HumanB.hpp"

humanB::humanB(std::string name) : _name(name)
{
    _Weapon = NULL;
}

humanB::~humanB()
{
    std::cout << _name << " destroyed" << std::endl;

}

void humanB::setWeapon(Weapon &weapon)
{
    this->_Weapon = &weapon;
}

void humanB::attack() const
{
    if (_Weapon && !_Weapon->getRefType().empty())
        std::cout << _name << " attacks with their " << _Weapon->getRefType() << std::endl;
    else
        std::cout << _name << " cannot attack without weapon" << std::endl;
}
