/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:42:18 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/13 16:47:10 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP
#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(Fixed const &instance);
    Fixed &operator=(Fixed const &rhs);
    Fixed(int const intNb);
    Fixed(float const floatNb);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed &min(Fixed &nb1, Fixed &nb2);
    const static Fixed &min(const Fixed &nb1, const Fixed &nb2);
    static Fixed &max(Fixed &nb1, Fixed &nb2);
    const static Fixed &max(const Fixed &nb1, const Fixed &nb2);

    bool operator>(Fixed const &rhs);
    bool operator<(Fixed const &rhs);
    bool operator>=(Fixed const &rhs);
    bool operator<=(Fixed const &rhs);
    bool operator==(Fixed const &rhs);
    bool operator!=(Fixed const &rhs);
    
    Fixed operator+(Fixed const &rhs);
    Fixed operator-(Fixed const &rhs);
    Fixed operator*(Fixed const &rhs);
    Fixed operator/(Fixed const &rhs);
    
    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    

private:
    int _fix;
    static const int _numBits;
};
std::ostream &operator<<(std::ostream &ost, Fixed const &rhs);
#endif