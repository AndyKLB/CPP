/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:22 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:12:36 by ankammer         ###   ########.fr       */
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
    std::cout << "Operator constructor called" << std::endl;
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
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
    
}
