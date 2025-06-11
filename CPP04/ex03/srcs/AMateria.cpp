/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:59:34 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/11 15:14:46 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AMateria.hpp"

AMateria::AMateria() : _type("undefined")
{
    std::cout << "Default AMateria constructor called" << std::endl;
}
AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "Set type AMateria constructor called" << std::endl;
}
AMateria::AMateria(const AMateria &src)
{
    std::cout << "Copy AMateria constructor called" << std::endl;
    this->_type = src.getType();
}
const AMateria &AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}
AMateria::~AMateria()
{
    std::cout << "Default AMateria destructor called" << std::endl;
}

const std::string &AMateria::getType() const
{
    return (_type);
}
void AMateria::setType(const std::string &type)
{
    this->_type = type;
}

void AMateria::use(ICharacter &target)
{
std::cout << "* uses a generic materia on " << target.getName() << " *" << std::endl;
    
}
