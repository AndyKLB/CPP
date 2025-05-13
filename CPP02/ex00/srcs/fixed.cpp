/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:22:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/12 15:41:26 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fixed.hpp"

Fixed::Fixed() : _fix(0)
{
    std::cout << "Defaut constructor called" << std::endl;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(Fixed const &instance)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = instance;
}
Fixed &Fixed::operator=(Fixed const &rhs)
{
    if (this != &rhs)
        this->_fix = rhs.getRawBits();
    return (*this);
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fix);    
}
void Fixed::setRawBits(int const raw)
{
    _fix = raw; 
}

const int Fixed::_numBits = 8;