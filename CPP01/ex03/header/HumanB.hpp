/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:18:03 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/22 13:57:48 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_HPP
#define HUMAN_B_CLASS_HPP
#include <iostream>
#include <string>
#include "../header/Weapon.hpp"

class humanB
{
public:
    humanB(std::string name);
    ~humanB();
    void attack() const;
    void setWeapon(Weapon &weapon);

private:
    Weapon *_Weapon;
    std::string _name;
};

#endif