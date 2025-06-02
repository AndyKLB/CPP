/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diamondtrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:08:01 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 14:02:43 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_CLASS_HPP
#define DIAMONDTRAP_CLASS_HPP
#include "../header/fragtrap.hpp"
#include "../header/scavtrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    DiamondTrap();
    DiamondTrap(const std::string &name); // a ajouter sur les autres exos (const &)
    DiamondTrap(const DiamondTrap &instance);
    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &rhs);

    void whoAmI();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void highFivesGuys(void);
    void guardGate();
    std::string getMyName() const;

private:
    std::string _name;
};

std::ostream &operator<<(std::ostream &ost, const DiamondTrap &rhs);

#endif