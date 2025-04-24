/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:55:53 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/24 10:52:11 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

int main()
{
    std::cout << "first zombie created on the heap" << std::endl;
    Zombie *john = newZombie("john");
    if (!john)
    {
        std::cerr << "error creating newZombie" << std::endl;
        return (1);
    }
    john->announce();
    delete (john);
    std::cout << "second zombie created on the stack outside the class" << std::endl;
    randomChump("alice");
    std::cout << "last zombie created on the stack in the class" << std::endl;
    Zombie rick("rick");
    rick.announce();
}