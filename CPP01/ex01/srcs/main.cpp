/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:23:16 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 14:23:33 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

int main()
{
    int n = 10;
    std::string name = "Goku";
    Zombie *zombieGroup = zombieHorde(n, name);
    for(int i = 1; i <= n; i++)
    {
        std::cout << zombieGroup[i - 1].getName() << " zombie number " << i << " says:" << std::endl;
        zombieGroup[i - 1].announce();
    }
    delete [] zombieGroup;
    return (0);
}