/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:14 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/27 14:16:56 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &instance);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &rhs);

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    std::string getName() const;
    int getHitPoints() const;
    int getEnergy() const;
    int getAttackDamage() const;
    void setName(std::string name) ;
    void setHitPoints(int amount) ;
    void setEnergy(int amount) ;
    void setAttackDamage(int amount) ;

protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energy;
    unsigned int _attackDamage;
};

// std::ostream & operator<<(const std::ostream &ost, const ClapTrap &rhs);

#endif