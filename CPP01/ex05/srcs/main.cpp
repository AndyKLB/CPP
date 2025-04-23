/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:35 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/23 15:18:40 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "invalid arguments: <complain level>" << std::endl;
        return (1);
    }
    Harl complainLevel;
    complainLevel.complain(argv[1]);
    return (0);
}