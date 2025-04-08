/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/08 17:58:31 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::createContact(int index)
{
}
std::string Contact::_strimInfos(std::string str) const
{
    if (str.length() > 10)
        return(str.substr(0, 9) + ".");
    return(str);
}

void Contact::printContact(int index) const
{
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << this->_strimInfos(this->_firstName);
    std::cout << "|" << std::setw(10) << this->_strimInfos(this->_lastName);
    std::cout << "|" << std::setw(10) << this->_strimInfos(this->_nickName);
    std::cout << "|" << std::endl;
}