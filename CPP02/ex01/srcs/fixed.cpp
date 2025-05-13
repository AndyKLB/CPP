/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:22:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/13 14:10:37 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fixed.hpp"

Fixed::Fixed() : _fix(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const &instance)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = instance;
}
Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fix = rhs.getRawBits();
    return (*this);
}
Fixed::Fixed(int const intNb)
{
    std::cout << "Int constructor called" << std::endl;
    _fix = intNb * (1 << _numBits);
}
Fixed::Fixed(float const floatNb)
{
    std::cout << "Float constructor called" << std::endl;
    _fix = roundf(floatNb * (1 << _numBits));
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (_fix);
}
void Fixed::setRawBits(int const raw)
{
    _fix = raw;
}

float Fixed::toFloat(void) const
{
    return ((static_cast <float>(_fix) / (1 << _numBits)));
}
int Fixed::toInt(void) const
{
    return (_fix / (1 << _numBits));

}
std::ostream &operator<<(std::ostream &ost, Fixed const &rhs)
{
    ost << rhs.toFloat();
    return (ost);
}

const int Fixed::_numBits = 8;