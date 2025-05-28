/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/28 15:42:49 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fragtrap.hpp"

int main()
{
    FragTrap jack("Jack");
    FragTrap victor("Victor");

    std::cout << victor;
    std::cout << jack;

    jack.highFivesGuys();
    victor.highFivesGuys();
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
