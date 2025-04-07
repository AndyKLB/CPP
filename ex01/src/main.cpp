/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:40 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/07 16:37:33 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void print_option()
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << "|          Options          |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "|  ADD      add new contact |" << std::endl;
    std::cout << "|  SEARCH   search  contact |" << std::endl;
    std::cout << "|  EXIT     exit program    |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

int main()
{
    std::string choice;
    print_option();
    while (1)
    {
        std::cout << "enter an option:  ";
        std::getline(std::cin, choice);
        if (!choice.compare("ADD"))
        {
            // TODO
            print_option();
        }
        else if (!choice.compare("SEARCH"))
        {
            // TODO
            print_option();
        }
        else if (!choice.compare("EXIT") || std::cin.eof())
            break;
        else
        {
            std::cout << "invalid option, retry please" << std::endl;
            print_option();
        }
    }
    return (0);
}