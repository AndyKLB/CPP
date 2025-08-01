/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:19:31 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 13:41:04 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP_CLASS
#define FRAGTRAP_HPP_CLASS
#include "claptrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &instance);
    ~FragTrap();

    FragTrap &operator=(const FragTrap &rhs);

    void highFivesGuys(void);
    void attack(const std::string &target);

private:
};

std::ostream &operator<<(std::ostream &ost, const FragTrap &rhs);

#endif