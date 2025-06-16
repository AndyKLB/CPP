/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:33:07 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:56:56 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
    std::cout << "Default AAnimal constructor called" << std::endl;
}
AAnimal::AAnimal(const AAnimal &src)
{
    std::cout << "Copy AAnimal constructor called" << std::endl;

    this->_type = src._type;
}
AAnimal &AAnimal::operator=(const AAnimal &rhs)
{

    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}
AAnimal::~AAnimal()
{
    std::cout << "Default AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->_type);
}

void AAnimal::makeSound() const
{
    std::cout << "No Generic animal sound" << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const AAnimal &rhs)
{
    ost  << "Type: "<< rhs.getType();
    return (ost);
}



void makeSpeak(const AAnimal & aanimal)
{
	aanimal.makeSound();
}