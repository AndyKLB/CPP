/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:52 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 14:16:35 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP
#include "../header/Contact.hpp"
#include <sstream>
#include <limits>

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact() const;
    void printAllContact() const;

private:
    Contact _phoneContact[8];
    static int _nbOfContact;
};

#endif