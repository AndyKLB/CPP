/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:33:07 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:55:31 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Default Animal constructor called" << std::endl;
}
Animal::Animal(const Animal &src)
{
    std::cout << "Copy Animal constructor called" << std::endl;

    this->_type = src._type;
}
Animal &Animal::operator=(const Animal &rhs)
{

    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}
Animal::~Animal()
{
    std::cout << "Default Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (this->_type);
}

void Animal::makeSound() const
{
    std::cout << "Generic animal sound" << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const Animal &rhs)
{
    ost  << "Type: "<< rhs.getType();
    return (ost);
}

void makeSpeak(const Animal & animal)
{
	animal.makeSound();
}
