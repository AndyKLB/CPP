/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:24 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:12:32 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Default Cure constructor called" << std::endl;
}
Cure::Cure(const Cure &src)
{
    std::cout << "Copy Cure constructor called" << std::endl;

    this->_type = src.getType();
}
const Cure &Cure::operator=(const Cure &rhs)
{
    std::cout << "Operator constructor called" << std::endl;
    if (this != &rhs)
        this->_type = rhs.getType();

    return (*this);
}
Cure::~Cure()
{
    std::cout << "Default Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
    AMateria *newCure = new Cure();
    return (newCure);
}
void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
