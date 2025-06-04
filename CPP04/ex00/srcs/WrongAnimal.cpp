/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:49:52 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 15:09:10 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "Copy WrongAnimal constructor called" << std::endl;
    this->_type = src.getType();
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal destructor called" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return (this->_type);
}
void WrongAnimal::makeSound() const
{
    std::cout << "I'm not a valid Animal" << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const WrongAnimal &rhs)
{
    ost  << "Type: "<< rhs.getType();
    return (ost);
}