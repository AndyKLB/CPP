/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:56:18 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 13:40:01 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/scavtrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default scavtrap constructor called" << std::endl;
    setHitPoints(100);
    setEnergy(50);
    setAttackDamage(20);
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "String name scavtrap constructor called" << std::endl;
    setHitPoints(100);
    setEnergy(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &instance) : ClapTrap(instance)
{
    std::cout << "Copy scavtrap constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}
ScavTrap::~ScavTrap()
{
    std::cout << "Default destructor scavtrap called" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << getName() << " is now in gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (getHitPoints() <= 0)
        std::cout << "Scavtrap " << _name << " cannot attack because he's dead" << std::endl;
    else if (getEnergy() <= 0)
        std::cout << "Scavtrap " << _name << " no energy available, cannot attack" << std::endl;
    else
    {
        std::cout << "Scavtrap " << _name << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        setEnergy(getEnergy() - 1);
    }
}

std::ostream &operator<<(std::ostream &ost, const ScavTrap &rhs)
{
    ost << "Name: " << rhs.getName() << std::endl;
    ost << "Energy: " << rhs.getEnergy() << std::endl;
    ost << "Hit Points: " << rhs.getHitPoints() << std::endl;
    ost << "Attack damage: " << rhs.getAttackDamage() << std::endl
        << std::endl;
    return (ost);
}
