/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:47:08 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/31 15:00:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: bad arguments usage: <prog> <expression>" << std::endl;
        return (1);
    }
    RPN rpn;
    try
    {
        std::cout << rpn.rpnCalcul(argv[1]) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}