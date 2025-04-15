/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:43 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/10 15:17:03 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
    this->_phoneContact[_nbOfContact % 8].createContact(_nbOfContact % 8);
    _nbOfContact++;
}

void PhoneBook::printAllContact() const
{
    int limit = _nbOfContact < 8 ? _nbOfContact : 8;
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;
    for (int i = 0; i < limit; i++)
        this->_phoneContact[i].printContact(i);
    std::cout << "+-------------------------------------------+" << std::endl;
}

void PhoneBook::searchContact() const
{
    int indexInt;
    std::string indexStr;

    if (_nbOfContact == 0)
    {
        std::cout << "no contact to display, add a contact before" << std::endl;
        return;
    }
    this->printAllContact();
    std::cout << std::endl;
    while (1)
    {
        std::cout << "enter index of the contact to display: " << std::flush;
        std::getline(std::cin >> std::ws, indexStr);
        std::stringstream ss(indexStr);
        ss >> indexInt;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "getline error" << std::endl;
        }
        else if (ss.fail())
        {
            ss.clear();
            ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid input not an int" << std::endl;
        }
        else if ((indexInt < 0 || indexInt > 7))
        {
            if (indexInt >= _nbOfContact)
                std::cout << "not a valid index, index between 0 and 7" << std::endl;
        }
        else if (indexInt >= _nbOfContact)
            std::cout << "no contact at this index, select a valid index" << std::endl;
        else
            break;
    }
    this->_phoneContact[indexInt].indexContact(indexInt);
}

int PhoneBook::_nbOfContact = 0;