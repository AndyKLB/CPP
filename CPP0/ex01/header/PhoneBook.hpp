/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:52 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/08 17:58:13 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "../header/Contact.hpp"

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