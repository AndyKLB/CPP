/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diamondtrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:08:03 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 12:31:08 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/diamondtrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "Default constructor DiamondTrap called" << std::endl;
    setName(ClapTrap::getName() + "_clap_name");
    setHitPoints(FragTrap::getDefaultHitPoints());
    setEnergy(ScavTrap::getDefaultEnergy());
    setAttackDamage(FragTrap::getDefaultAttackDamage());
}
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    std::cout << "String constructor DiamondTrap called" << std::endl;
    setHitPoints(FragTrap::getDefaultHitPoints());
    setEnergy(ScavTrap::getDefaultEnergy());
    setAttackDamage(FragTrap::getDefaultAttackDamage());
}
DiamondTrap::DiamondTrap(const DiamondTrap &instance)
{
    std::cout << "Copy constructor DiamondTrap called" << std::endl;
    this->setName(instance.getName());
    this->setHitPoints(instance.getHitPoints());
    this->setEnergy(instance.getEnergy());
    this->setAttackDamage(instance.getAttackDamage());
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "Default destructor DiamondTrap called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    if (this != &rhs)
    {
        this->setName(rhs.getName());
        this->setHitPoints(rhs.getHitPoints());
        this->setEnergy(rhs.getEnergy());
        this->setAttackDamage(rhs.getAttackDamage());
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap : Hello my DiamondTrap name is: " << getName() << std::endl;
    std::cout << "DiamondTrap : Hello my ClapTrap name is: " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::highFivesGuys(void)
{
    if (getHitPoints() > 0)
        std::cout << "DiamondTrap " << _name << " is requesting high fives!" << std::endl;
    else
        std::cout << "DiamondTrap " << _name << " is dead, cannot request high fives!" << std::endl;
}
void DiamondTrap::guardGate()
{
    std::cout << "DiamondTrap " << getName() << " is now in gate keeper mode" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::takeDamage(unsigned int amount)
{

    if (getHitPoints() <= 0)
        std::cout << "DiamondTrap " << _name << " is already dead you cannot attack him" << std::endl;
    else
        std::cout << "DiamondTrap " << _name << " has taken " << amount << " of damage" << std::endl;
    if (amount >= _hitPoints)
    {
        setHitPoints(0);
        std::cout << "DiamondTrap " << _name << " has been killed" << std::endl;
    }
    else
    {
        setHitPoints(amount);
        std::cout << "DiamondTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
    }
}
void DiamondTrap::beRepaired(unsigned int amount)
{
    if (getHitPoints() <= 0)
        std::cout << "DiamondTrap " << _name << " is already dead and cannot be repaired" << std::endl;
    else if (getEnergy() <= 0)
        std::cout << "DiamondTrap " << _name << " cannot be repaired, no energy available" << std::endl;
    else
    {
        std::cout << "DiamondTrap " << _name << " has been repaired and gained " << amount << " of hit points" << std::endl;
        setHitPoints(getHitPoints() + amount);
        std::cout << "DiamondTrap " << _name << " has now " << _hitPoints << " of hit points" << std::endl;
        setEnergy(getEnergy() - 1);
    }
}

std::ostream &operator<<(std::ostream &ost, const DiamondTrap &rhs)
{
    ost << "Name: " << rhs.getName() << std::endl;
    ost << "Hit points: " << rhs.getHitPoints() << std::endl;
    ost << "Energy: " << rhs.getEnergy() << std::endl;
    ost << "Attack damage: " << rhs.getAttackDamage() << std::endl;
    ost << std::endl;
    return (ost);
}
