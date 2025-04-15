/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:40 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/10 15:19:01 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../header/PhoneBook.hpp"

void print_option()
{
    std::cout << "+---------------------------+" << std::endl;
    std::cout << "|          Options          |" << std::endl;
    std::cout << "+---------------------------+" << std::endl;
    std::cout << "|      Make your choice     |" << std::endl;
    std::cout << "|  ADD      add new contact |" << std::endl;
    std::cout << "|  SEARCH   search  contact |" << std::endl;
    std::cout << "|  EXIT     exit program    |" << std::endl;
    std::cout << "+---------------------------+" << std::endl;
}

int main()
{
    PhoneBook repertoire;
    std::string choice;
    while (1)
    {
        print_option();
        std::cout << "enter an option:  " << std::flush;
        std::getline(std::cin, choice);
        if (!choice.compare("ADD"))
            repertoire.addContact();
        else if (!choice.compare("SEARCH"))
            repertoire.searchContact();
        else if (!choice.compare("EXIT") || std::cin.eof())
            break;
        else
            std::cout << "invalid option, try again" << std::endl;
    }
    return (0);
}