/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:03:47 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 14:21:37 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombieGroup = new(std::nothrow) Zombie[N];
    if (!zombieGroup) // optionnel car cpp en cas d'echec lance std::bad_alloc et s'arrete sauf si catch ou avec std::nothrow
    {
        std::cerr << "error on alloc new zombieHorde" << std::endl;
        exit (1);
    }
    else
    {
        for (int i = 0; i < N; i++)
            zombieGroup[i].setName(name);
        return (zombieGroup);
    }
}