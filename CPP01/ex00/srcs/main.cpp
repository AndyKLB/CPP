/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:55:53 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 12:47:27 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

int main()
{
    std::cout << "first zombie created on the heap" << std::endl;
    Zombie *goku = newZombie("Goku");
    if (!goku)
    {
        std::cerr << "error creating newZombie" << std::endl;
        return (1);
    }
    goku->announce();
    delete (goku);
    std::cout << "second zombie created on the stack outside the class" << std::endl;
    randomChump("Gohan");
    std::cout << "last zombie created on the stack in the class" << std::endl;
    Zombie vegeta("Vegeta");
    vegeta.announce();
}