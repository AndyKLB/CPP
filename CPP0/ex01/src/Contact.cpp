/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 17:12:32 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool Contact::checkInfos(std::string infos)
{
    for (std::string::iterator it = infos.begin(); it != infos.end(); it++)
    {
        if (!std::isalnum(*it))
            return (1);
    }
    return (0);
}

std::string Contact::putInfos(std::string message)
{
    std::string input;

    while (!std::cin.eof())
    {
        std::cout << message << std::flush;
        std::getline(std::cin >> std::ws, input);
        std::cout << std::endl;
        if (std::cin.fail()) // verifie si la lecture getline a reussi
        {
            std::cin.clear();                                                   // reinitialise etat de cin (flags)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore ce qui reste pour vider le buffer streamsize = type T (int, ..) max ou jusqua un saut de ligne
            std::cout << "error getline";
        }
        else if (!checkInfos(input))
            break;
        else
            std::cout << "invalid input, not alphanumeric" << std::endl;
    }
    return (input);
}

void Contact::createContact(int index)
{
    this->_firstName = putInfos("enter first name: ");
    this->_lastName = putInfos("enter last name: ");
    this->_nickName = putInfos("enter nick name: ");
    this->_phoneNumber = putInfos("enter phone number: ");
    this->_darkestSecret = putInfos("enter darkest decret: ");
    this->_index = index;
}
std::string Contact::_strimInfos(std::string str) const
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void Contact::printContact(int index) const
{
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << this->_strimInfos(this->_firstName);
    std::cout << "|" << std::setw(10) << this->_strimInfos(this->_lastName);
    std::cout << "|" << std::setw(10) << this->_strimInfos(this->_nickName);
    std::cout << "|" << std::endl;
}

void Contact::indexContact(int index) const
{
    std::cout << "index: " << index << std::endl;
    std::cout << "first name: " << this->_firstName << std::endl;
    std::cout << "last name: " << this->_lastName << std::endl;
    std::cout << "nick name: " << this->_nickName << std::endl;
    std::cout << "phone number: " << this->_phoneNumber << std::endl;
    std::cout << "darkest secret: " << this->_darkestSecret << std::endl;
    std::cout << std::endl;

}
