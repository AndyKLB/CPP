/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/29 13:35:40 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/diamondtrap.hpp"

int main()
{
    DiamondTrap jack("Jack");
    DiamondTrap victor("Victor");

    std::cout << victor;
    std::cout << jack;

    jack.highFivesGuys();
    victor.highFivesGuys();
    
    jack.guardGate();
    victor.guardGate();
    std::cout << std::endl;

    jack.attack("Victor");
    victor.takeDamage(30);
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    jack.attack("Victor");
    victor.takeDamage(30);
    std::cout << std::endl;

    jack.attack("Victor");
    victor.takeDamage(30);
    std::cout << std::endl;

    jack.attack("Victor");
    victor.takeDamage(30);
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    jack.attack("Victor");
    victor.takeDamage(30);
    victor.beRepaired(50);
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    jack.attack("victor");
    victor.takeDamage(30);
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    victor.attack("jack");
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;
}
