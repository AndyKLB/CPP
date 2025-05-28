/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:56:05 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/28 16:08:36 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_CLASS_HPP
#define SCAV_TRAP_CLASS_HPP
#include "claptrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap &instance);
    ScavTrap &operator=(const ScavTrap &rhs);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
};

std::ostream & operator<<(std::ostream &ost, const ScavTrap & rhs);

#endif
