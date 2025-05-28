/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/28 12:52:53 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/claptrap.hpp"

int main()
{
    ClapTrap jack("Jack");
    ClapTrap victor("Victor");

    std::cout << jack;
    std::cout << victor;

    jack.attack("Victor");
    victor.takeDamage(5);
    victor.beRepaired(15);

    std::cout << jack;
    std::cout << victor;

    victor.attack("Jack");
    jack.takeDamage(9);
    jack.beRepaired(19);

    jack.attack("Victor");
    victor.takeDamage(30); // victor dead
    victor.beRepaired(50); // impossible

    jack.attack("victor");
    victor.takeDamage(90); // already dead

    victor.attack("jack"); // impossible

    std::cout << jack;
    std::cout << victor;
}
