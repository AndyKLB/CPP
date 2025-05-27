/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/27 14:43:44 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/claptrap.hpp"
#include "../header/scavtrap.hpp"

int main()
{
    ScavTrap jack("Jack");
    ScavTrap victor("Victor");

    std::cout << victor;
    std::cout << jack;

    jack.attack("Victor");
    victor.takeDamage(20);

    std::cout << victor;
    std::cout << jack;

    jack.attack("Jack");
    victor.takeDamage(20);

    jack.attack("Jack");
    victor.takeDamage(20);

    jack.attack("Jack");
    victor.takeDamage(20);

    jack.attack("Jack");
    victor.takeDamage(20);

    std::cout << victor;
    std::cout << jack;

    jack.attack("Victor");
    victor.takeDamage(20); // victor dead
    victor.beRepaired(50); // impossible

    std::cout << victor;
    std::cout << jack;

    jack.attack("victor");
    victor.takeDamage(20); // already dead

    std::cout << victor;
    std::cout << jack;

    victor.attack("jack"); // impossible

    std::cout << victor;
    std::cout << jack;
}
