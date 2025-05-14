/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:22:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/13 17:25:10 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fixed.hpp"

Fixed::Fixed() : _fix(0)
{
}
Fixed::Fixed(Fixed const &instance)
{
    *this = instance;
}
Fixed &Fixed::operator=(Fixed const &rhs)
{
    if (this != &rhs)
        this->_fix = rhs.getRawBits();
    return (*this);
}
Fixed::Fixed(int const intNb)
{
    _fix = intNb * (1 << _numBits);
}
Fixed::Fixed(float const floatNb)
{
    _fix = roundf(floatNb * (1 << _numBits));
}
Fixed::~Fixed()
{
}
int Fixed::getRawBits(void) const
{
    return (_fix);
}
void Fixed::setRawBits(int const raw)
{
    _fix = raw;
}

float Fixed::toFloat(void) const
{
    return ((static_cast<float>(_fix) / (1 << _numBits)));
}
int Fixed::toInt(void) const
{
    return (_fix / (1 << _numBits));
}

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2)
{
    if (nb1.getRawBits() > nb2.getRawBits())
        return (nb2);
    return (nb1);
}
const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
    if (nb1.getRawBits() > nb2.getRawBits())
        return (nb2);
    return (nb1);
}
Fixed &Fixed::max(Fixed &nb1, Fixed &nb2)
{
    if (nb1.getRawBits() > nb2.getRawBits())
        return (nb1);
    return (nb2);
}
const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
    if (nb1.getRawBits() > nb2.getRawBits())
        return (nb1);
    return (nb2);
}

bool Fixed::operator>(Fixed const &rhs)
{
    return (this->getRawBits() > rhs.getRawBits());
}
bool Fixed::operator<(Fixed const &rhs)
{
    return (this->getRawBits() < rhs.getRawBits());
}
bool Fixed::operator>=(Fixed const &rhs)
{
    return (this->getRawBits() >= rhs.getRawBits());
}
bool Fixed::operator<=(Fixed const &rhs)
{
    return (this->getRawBits() <= rhs.getRawBits());
}
bool Fixed::operator==(Fixed const &rhs)
{
    return (this->getRawBits() == rhs.getRawBits());
}
bool Fixed::operator!=(Fixed const &rhs)
{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs)
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed Fixed::operator-(Fixed const &rhs)
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed Fixed::operator*(Fixed const &rhs)
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed Fixed::operator/(Fixed const &rhs)
{
    if (rhs.getRawBits() == 0)
    {
        std::cout << "Division by 0 impossible" << std::endl;
        return (Fixed());
    }
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++()
{
    ++_fix;
    return (*this);
}
Fixed &Fixed::operator--()
{
    --_fix;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this); // pas ++_fix car deja defini au dessus (valide mais redondant)
    return (tmp);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return (tmp);
}

std::ostream &operator<<(std::ostream &ost, Fixed const &rhs)
{
    ost << rhs.toFloat();
    return (ost);
}
const int Fixed::_numBits = 8;