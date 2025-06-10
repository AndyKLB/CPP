/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:22 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/10 15:17:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Default Ice constructor called" << std::endl;
}
Ice::Ice(const Ice &src)
{
    std::cout << "Copy Ice constructor called" << std::endl;
    this->_type = src.getType();
}
Ice::~Ice()
{
    std::cout << "Default Ice destructor called" << std::endl;
}

const Ice &Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

AMateria *Ice::clone() const
{
    AMateria *newIce = new Ice();
    return (newIce);
}
void Ice::use(ICharacter &target)
{
}