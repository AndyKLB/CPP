/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 13:36:45 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/claptrap.hpp"
#include "../header/scavtrap.hpp"

int main()
{
    ScavTrap jack("Jack");
    ScavTrap victor("Victor");
    ScavTrap victori(jack);

    std::cout << "copy of Jack: " << std::endl << victori;
    std::cout << victor;
    std::cout << jack;

    jack.guardGate();
    victor.guardGate();
    std::cout << std::endl;

    jack.attack("Victor");
    victor.takeDamage(20);
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    jack.attack("Jack");
    victor.takeDamage(20);
    std::cout << std::endl;

    jack.attack("Victor");
    victor.takeDamage(20);
    std::cout << std::endl;

    jack.attack("Victor");
    victor.takeDamage(20);
    std::cout << std::endl;

    jack.attack("Victor");
    victor.takeDamage(20);
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    jack.attack("Victor");
    victor.takeDamage(20); // victor dead
    victor.beRepaired(50); // impossible
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    jack.attack("victor");
    victor.takeDamage(20); // already dead
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;

    victor.attack("jack"); // impossible
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;
}
