/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:43 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/08 17:58:21 by ankammer         ###   ########.fr       */
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
    for (int i = 0; i < limit; i++)
        this->_phoneContact[i].printContact(i);
    std::cout << "+-------------------------------------------+" << std::endl;
}

void PhoneBook::searchContact() const
{
    // TODO
    printAllContact();
}

int PhoneBook::_nbOfContact = 0;