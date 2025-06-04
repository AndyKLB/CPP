/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:46:22 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 15:08:01 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Default Dog constructor called" << std::endl;
    _type = "Dog";
}
Dog::Dog(const Dog &src)
{
    std::cout << "Copy Dog constructor called" << std::endl;
    this->_type = src.getType();
}
Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}
Dog::~Dog()
{
    std::cout << "Default Dog Destructor called" << std::endl;
}
void Dog::makeSound() const
{
    std::cout << _type << ": wouf wouf" << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const Dog &rhs)
{
    ost  << "Type: "<< rhs.getType();
    return (ost);
}