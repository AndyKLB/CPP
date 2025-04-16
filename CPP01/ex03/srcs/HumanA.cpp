/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:37 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 16:59:20 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/HumanA.hpp"

humanA::humanA(std::string name, Weapon &weapon) : _name(name), _Weapon(weapon)
{
}

humanA::~humanA()
{
    std::cout << _name << " destroyed" << std::endl;

}

void humanA::attack() const
{
    std::cout << _name << " attacks with their " << _Weapon.getRefType() << std::endl;
}
