/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:14 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 12:39:55 by ankammer         ###   ########.fr       */
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

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergy() const;
    unsigned int getAttackDamage() const;
    void setName(std::string name) ;
    void setHitPoints(unsigned int amount) ;
    void setEnergy(unsigned int amount) ;
    void setAttackDamage(unsigned int amount) ;

protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energy;
    unsigned int _attackDamage;
};

std::ostream & operator<<(std::ostream &ost, const ClapTrap &rhs);

#endif