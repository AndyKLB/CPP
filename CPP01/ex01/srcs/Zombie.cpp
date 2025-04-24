/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:50:24 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/24 14:49:22 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

Zombie::Zombie()
{
    _zombieNb++;
}
Zombie::~Zombie()
{
    std::cout << _name << " number " << _zombieNb << " has been destroyed, ";
    _zombieNb--;
    std::cout << _zombieNb << " zombie(s) still alive" << std::endl;
}

void Zombie::announce() const
{
    std::cout << " says: BraiiiiiiinnnzzzZ..." << std::endl;
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