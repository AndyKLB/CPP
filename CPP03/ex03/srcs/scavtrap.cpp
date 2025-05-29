/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:56:18 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/29 17:27:28 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/scavtrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    std::cout << "Default scavtrap constructor called" << std::endl;
    setHitPoints(100);
    // setEnergy(50);
    setAttackDamage(20);
    _energy = 50;
}
ScavTrap::ScavTrap(const std::string & name) : ClapTrap(name) // possible d'use'setName dans le corps de la fonction mais plus opti d'use le constr de claptrap
{
    std::cout << "String name scavtrap constructor called" << std::endl;
    setHitPoints(100);
    // setEnergy(50);
    _energy = 50;

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
void ScavTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() <= 0)
    {
        std::cout << "Scavtrap " << _name << " is already dead you cannot attack him" << std::endl;
        return;
    }
    else
        std::cout << "Scavtrap " << _name << " has taken " << amount << " of damage" << std::endl;
    if (amount >= getHitPoints())
    {
        setHitPoints(0);
        std::cout << "Scavtrap " << _name << " has been killed" << std::endl;
    }
    else
    {
        setHitPoints(getHitPoints() - amount);
        std::cout << "Scavtrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (getHitPoints() <= 0)
        std::cout << "Scavtrap " << _name << " is already dead and cannot be repaired" << std::endl;
    else if (getEnergy() <= 0)
        std::cout << "Scavtrap " << _name << " cannot be repaired, no energy available" << std::endl;
    else
    {
        std::cout << "Scavtrap " << _name << " has been repaired and gained " << amount << " of hit points" << std::endl;
        setHitPoints(getHitPoints() + amount);
        std::cout << "Scavtrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
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
