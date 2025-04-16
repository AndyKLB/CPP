/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:32:21 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 15:12:25 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

#include <iostream>
#include <string>
#include <bits/stdc++.h>

class Zombie
{
public:
    Zombie();
    ~Zombie();

    void setName(std::string name);
    std::string getName() const;
    void announce() const;

private:
    std::string _name;
    static int _zombieNb;
};

Zombie *zombieHorde(int N, std::string name);

#endif