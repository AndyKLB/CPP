/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:54:05 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 16:47:28 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Default WrongCat constructor called" << std::endl;
    _type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "Copy WrongCat constructor called" << std::endl;
    this->_type = src.getType();
}
WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}
WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: wouf $)" << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const WrongCat &rhs)
{
    ost  << "Type: "<< rhs.getType();
    return (ost);
}