/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:49 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/10 15:00:17 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>

class Contact
{
public:
    Contact();
    ~Contact();
    void createContact(int index);
    void printContact(int index) const;
    void indexContact(int index) const;

private:
    int _index;
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;
    std::string _strimInfos(std::string str) const;
    std ::string putInfos(std::string);
    bool checkInfos(std::string infos);
};

#endif