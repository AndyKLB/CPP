/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:50:24 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 14:58:59 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

Zombie::Zombie()
{
    _zombieNb++;
}
Zombie::~Zombie()
{
    _zombieNb--;
    std::cout << _name << " has been destroyed, ";
    std::cout << _zombieNb << " zombie(s) still alive" << std::endl;
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}
std::string Zombie::getName () const
{
    return(_name);
}


int Zombie::_zombieNb = 0;