/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:46:14 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/09 15:15:55 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain())
{
    std::cout << "Default Cat constructor called" << std::endl;
    _type = "Cat";
}
Cat::Cat(const Cat &src)
{
    std::cout << "Copy Cat constructor called" << std::endl;
    this->_type = src.getType();
    this->_brain = new Brain(*src._brain);
}
Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs.getType();
        // delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete (this->_brain);
    std::cout << "Default Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << getType() << ": Miaouuuu Miaouuuu Miaouuuu" << std::endl;
}

void Cat::setIdeas(const std::string &idea, int index)
{
    if (_brain)
        _brain->setIdeas(idea, index);
}
const std::string &Cat::getIdeas(int index) const
{
    static const std::string empty = "";
    if (_brain)
        return (_brain->getIdeas(index));
    return (empty);
}

const Brain *Cat::getBrain() const
{
    return (_brain);
}

std::ostream &operator<<(std::ostream &ost, const Cat &rhs)
{
    ost << "Type: " << rhs.getType() << std::endl;
    if (rhs.getBrain())
        ost << *(rhs.getBrain());
    return (ost);
}