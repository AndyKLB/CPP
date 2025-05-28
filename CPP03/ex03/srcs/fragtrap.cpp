/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:19:26 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/28 15:41:23 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fragtrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default fragtrap constructor called" << std::endl;

    setHitPoints(100);
    setEnergy(100);
    setAttackDamage(30);
}
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "String fragtrap constructor called" << std::endl;

    setHitPoints(100);
    setEnergy(100);
    setAttackDamage(30);
}
FragTrap::FragTrap(const FragTrap &instance) : ClapTrap(instance)
{
    std::cout << "Copy fragtrap constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "Default fragtrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (getHitPoints() > 0)
        std::cout << "Fragtrap " << _name << " is requesting high fives!" << std::endl;
    else
        std::cout << "Fragtrap " << _name << " is dead, cannot request high fives!" << std::endl;

}

void FragTrap::attack(const std::string &target)
{
    if (getHitPoints() <= 0)
        std::cout << "FragTrap " << _name << " cannot attack because he's dead" << std::endl;
    else if (getEnergy() <= 0)
        std::cout << "FragTrap " << _name << " no energy available, cannot attack" << std::endl;
    else
    {
        std::cout << "FragTrap " << _name << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        setEnergy(getEnergy() - 1);
    }
}
void FragTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() <= 0)
    {
        std::cout << "FragTrap " << _name << " is already dead you cannot attack him" << std::endl;
        return;
    }
    else
        std::cout << "FragTrap " << _name << " has taken " << amount << " of damage" << std::endl;
    if (amount >= getHitPoints())
    {
        setHitPoints(0);
        std::cout << "FragTrap " << _name << " has been killed" << std::endl;
    }
    else
    {
        setHitPoints(getHitPoints() - amount);
        std::cout << "FragTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
    }
}
void FragTrap::beRepaired(unsigned int amount)
{
    if (getHitPoints() <= 0)
        std::cout << "FragTrap " << _name << " is already dead and cannot be repaired" << std::endl;
    else if (getEnergy() <= 0)
        std::cout << "FragTrap " << _name << " cannot be repaired, no energy available" << std::endl;
    else
    {
        std::cout << "FragTrap " << _name << " has been repaired and gained " << amount << " of hit points" << std::endl;
        setHitPoints(getHitPoints() + amount);
        std::cout << "FragTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
        setEnergy(getEnergy() - 1);
    }
}

std::ostream &operator<<(std::ostream &ost, const FragTrap &rhs)
{
    ost << "Name: " << rhs.getName() << std::endl;
    ost << "Energy: " << rhs.getEnergy() << std::endl;
    ost << "Hit Points: " << rhs.getHitPoints() << std::endl;
    ost << "Attack damage: " << rhs.getAttackDamage() << std::endl
        << std::endl;
    return (ost);
}
