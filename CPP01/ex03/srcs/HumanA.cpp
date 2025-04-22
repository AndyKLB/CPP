/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:37 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/22 14:05:09 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/HumanA.hpp"

humanA::humanA(std::string name, Weapon &weapon) : _Weapon(weapon), _name(name)
{
}

humanA::~humanA()
{
    std::cout << _name << " destroyed" << std::endl;
}

void humanA::attack() const
{
    if (!_Weapon.getRefType().empty())
        std::cout << _name << " attacks with their " << _Weapon.getRefType() << std::endl;
    else
        std::cout << _name << " cannot attack without weapon" << std::endl;
}
