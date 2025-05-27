/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:56:18 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/27 14:46:39 by ankammer         ###   ########.fr       */
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
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "String name scavtrap constructor called" << std::endl;
    setHitPoints(100);
    setEnergy(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap &instance)
{
    std::cout << "Copy scavtrap constructor called" << std::endl;
    this->_name = instance.getName();
    this->_hitPoints = instance.getHitPoints();
    this->_energy = instance.getEnergy();
    this->_attackDamage = instance.getAttackDamage();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_hitPoints = rhs.getHitPoints();
        this->_energy = rhs.getEnergy();
        this->_attackDamage = rhs.getAttackDamage();
    }
    return (*this);
}
ScavTrap::~ScavTrap()
{
    std::cout << "Default destructor called" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << getName() << " is now in gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0)
        std::cout << "Scavtrap " << _name << " cannot attack because he's dead" << std::endl;
    else if (_energy <= 0)
        std::cout << "Scavtrap " << _name << " no energy available, cannot attack" << std::endl;
    else
    {
        std::cout << "Scavtrap " << _name << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        _energy--;
    }
}
void ScavTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "Scavtrap " << _name << " is already dead you cannot attack him" << std::endl;
        return;
    }
    else
        std::cout << "Scavtrap " << _name << " has taken " << amount << " of damage" << std::endl;
    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "Scavtrap " << _name << " has been killed" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "Scavtrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
        std::cout << "Scavtrap " << _name << " is already dead and cannot be repaired" << std::endl;
    else if (_energy <= 0)
        std::cout << "Scavtrap " << _name << " cannot be repaired, no energy available" << std::endl;
    else
    {
        std::cout << "Scavtrap " << _name << " has been repaired and gained " << amount << " of hit points" << std::endl;
        _hitPoints += amount;
        std::cout << "Scavtrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
        _energy--;
    }
}

std::ostream &operator<<(std::ostream &ost, ScavTrap &rhs)
{
    ost << "Name: " << rhs.getName() << std::endl;
    ost << "Energy: " << rhs.getEnergy() << std::endl;
    ost << "Hit Points: " << rhs.getHitPoints() << std::endl;
    ost << "Attack damage: " << rhs.getAttackDamage() << std::endl
        << std::endl;
    return (ost);
}
