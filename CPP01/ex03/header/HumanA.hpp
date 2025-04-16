/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:17:59 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 15:33:32 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_CLASS_HPP
#define HUMAN_A_CLASS_HPP
#include <iostream>
#include <string>
#include "../header/Weapon.hpp"

class humanA
{
public:
    humanA(std::string name, Weapon &weapon);
    ~humanA();
    void attack() const;

private:
    Weapon &_Weapon;
    std::string _name;
};

#endif