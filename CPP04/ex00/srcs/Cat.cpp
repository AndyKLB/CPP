/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:46:14 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 15:08:41 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Default Cat constructor called" << std::endl;
    _type = "Cat";
}
Cat::Cat(const Cat &src)
{
    std::cout << "Copy Cat constructor called" << std::endl;
    this->_type = src.getType();
}
Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Default Cat Destructor called" << std::endl;
    
}

void Cat::makeSound() const
{
    std::cout << getType() << ": Miaouuuu" << std::endl;
    
}

std::ostream &operator<<(std::ostream &ost, const Cat &rhs)
{
    ost  << "Type: "<< rhs.getType();
    return (ost);
}