/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:23:16 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/24 14:58:18 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

int main()
{
    int n = 10;
    std::string name = "rick";
    Zombie *zombieGroup = zombieHorde(n, name);

    for (int i = 1; i <= n; i++)
    {
        std::cout << zombieGroup[i - 1].getName() << " zombie number " << i;
        zombieGroup[i - 1].announce();
    }
    delete[] zombieGroup;
    return (0);
}