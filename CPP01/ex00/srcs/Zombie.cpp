/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:50:24 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/24 10:52:42 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "the zombie " << _name << " has been created" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed" << std::endl;
}

void Zombie::announce() const
{
    std::cout << _name << " says: BraiiiiiiinnnzzzZ..." << std::endl;
}