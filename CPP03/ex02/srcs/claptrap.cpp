/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:59:30 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 13:20:32 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/claptrap.hpp"

ClapTrap::ClapTrap() : _name("undefined"), _hitPoints(10), _energy(10), _attackDamage(0)
{
    std::cout << "Default constructor claptrap called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energy(10), _attackDamage(0)
{
    std::cout << "String name constructor claptrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &instance)
{
    std::cout << "Copy constructor claptrap called" << std::endl;

    this->_name = instance.getName();
    this->_hitPoints = instance.getHitPoints();
    this->_energy = instance.getEnergy();
    this->_attackDamage = instance.getAttackDamage();
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor claptrap called" << std::endl;
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
    if (getHitPoints() <= 0)
        std::cout << "ClapTrap " << _name << " cannot attack because he's dead" << std::endl;
    else if (getEnergy() <= 0)
        std::cout << "ClapTrap " << _name << " no energy available, cannot attack" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        _energy--;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead you cannot attack him" << std::endl;
        return;
    }
    else
        std::cout << "ClapTrap " << _name << " has taken " << amount << " of damage" << std::endl;
    if (amount >= _hitPoints)
    {
        setHitPoints(0);
        std::cout << "ClapTrap " << _name << " has been killed" << std::endl;
    }
    else
    {
        setHitPoints(amount);
        std::cout << "ClapTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (getHitPoints() <= 0)
        std::cout << "ClapTrap " << _name << " is already dead and cannot be repaired" << std::endl;
    else if (getEnergy() <= 0)
        std::cout << "ClapTrap " << _name << " cannot be repaired, no energy available" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " has been repaired and gained " << amount << " of hit points" << std::endl;
        setHitPoints(getHitPoints() + amount);
        std::cout << "ClapTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
        setEnergy(getEnergy() - 1);
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

void ClapTrap::setName(std::string name)
{
    _name = name;
}
void ClapTrap::setHitPoints(unsigned int amount)
{
    _hitPoints = amount;
}
void ClapTrap::setEnergy(unsigned int amount)
{
    _energy = amount;
}
void ClapTrap::setAttackDamage(unsigned int amount)
{
    _attackDamage = amount;
}

std::ostream &operator<<(std::ostream &ost, const ClapTrap &rhs)
{
    ost << rhs.getName();
    ost << rhs.getHitPoints();
    ost << rhs.getEnergy();
    ost << rhs.getAttackDamage();
    return (ost);
}
