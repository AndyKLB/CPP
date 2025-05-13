/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:42:18 by ankammer          #+#    #+#             */
/*   Updated: 2025/05/12 16:41:44 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP
#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(Fixed const &instance);
    Fixed &operator=(Fixed const &rhs);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int _fix;
    static const int _numBits;
};

#endif