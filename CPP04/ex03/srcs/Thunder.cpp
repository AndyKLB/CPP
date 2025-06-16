/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:32:22 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:12:49 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Thunder.hpp"

Thunder::Thunder() : AMateria("thunder")
{
    std::cout << "Default Thunder constructor called" << std::endl;
}
Thunder::Thunder(const Thunder &src)
{
    std::cout << "Copy Thunder constructor called" << std::endl;
    this->_type = src.getType();
}
Thunder::~Thunder()
{
    std::cout << "Default Thunder destructor called" << std::endl;
}

const Thunder &Thunder::operator=(const Thunder &rhs)
{
    std::cout << "Operator constructor called" << std::endl;
    if (this != &rhs)
        this->_type = rhs.getType();

    return (*this);
}

AMateria *Thunder::clone() const
{
    AMateria *newThunder = new Thunder();
    return (newThunder);
}
void Thunder::use(ICharacter &target)
{
    std::cout << "* shoots an thunder bolt at " << target.getName() << " *" << std::endl; 
    
}