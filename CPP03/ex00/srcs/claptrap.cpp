/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:59:30 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 12:38:56 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/claptrap.hpp"

ClapTrap::ClapTrap() : _name("undefined"), _hitPoints(10), _energy(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energy(10), _attackDamage(0)
{
    std::cout << "String name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &instance)
{
    std::cout << "Copy constructor called" << std::endl;

    this->_name = instance.getName();
    this->_hitPoints = instance.getHitPoints();
    this->_energy = instance.getEnergy();
    this->_attackDamage = instance.getAttackDamage();
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
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

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " cannot attack because he's dead" << std::endl;
    else if (_energy <= 0)
        std::cout << "ClapTrap " << _name << " no energy available, cannot attack" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        _energy--;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "Scavtrap " << _name << " is already dead you cannot attack him" << std::endl;
        return;
    }
    else
        std::cout << "ClapTrap " << _name << " has taken " << amount << " of damage" << std::endl;
    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " has been killed" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is already dead and cannot be repaired" << std::endl;
    else if (_energy <= 0)
        std::cout << "ClapTrap " << _name << " cannot be repaired, no energy available" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " has been repaired and gained " << amount << " of hit points" << std::endl;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
        _energy--;
    }
}

std::string ClapTrap::getName() const
{
    return (_name);
}
unsigned int ClapTrap::getHitPoints() const
{
    return (_hitPoints);
}
unsigned int ClapTrap::getEnergy() const
{
    return (_energy);
}
unsigned int ClapTrap::getAttackDamage() const
{
    return (_attackDamage);
}

std::ostream & operator<<(std::ostream &ost, const ClapTrap &rhs)
{
    ost << std::endl;
    ost << "Name: " << rhs.getName() << std::endl;
    ost << "Hitpoints: " << rhs.getHitPoints() << std::endl;
    ost << "Energy: " << rhs.getEnergy() << std::endl;
    ost << "Attack damage: " << rhs.getAttackDamage() << std::endl << std::endl;
    return (ost);
}
