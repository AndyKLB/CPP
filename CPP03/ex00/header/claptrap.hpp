/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:14 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 12:38:46 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &instance);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &rhs);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergy() const;
    unsigned int getAttackDamage() const;

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energy;
    unsigned int _attackDamage;
};

std::ostream & operator<<(std::ostream &ost, const ClapTrap &rhs);

#endif