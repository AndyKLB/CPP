/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/02 13:52:45 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/diamondtrap.hpp"

int main()
{
    DiamondTrap jack("Jack");
    DiamondTrap victor("Victor");
    DiamondTrap hoho;

    std::cout << hoho;
    std::cout << victor;
    std::cout << jack;
    
    hoho.whoAmI();
    jack.whoAmI();
    victor.whoAmI();
    std::cout << std::endl;
    
    jack.highFivesGuys();
    victor.highFivesGuys();
    std::cout << std::endl;

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

    jack.attack("Victor");
    victor.takeDamage(30);
    victor.beRepaired(50);
    std::cout << std::endl;


    jack.attack("victor");
    victor.takeDamage(30);
    std::cout << std::endl;



    victor.attack("jack");
    std::cout << std::endl;

    std::cout << victor;
    std::cout << jack;
}
