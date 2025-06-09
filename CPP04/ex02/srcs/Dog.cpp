/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:46:22 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/09 15:16:06 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain)
{
    std::cout << "Default Dog constructor called" << std::endl;
    _type = "Dog";
}
Dog::Dog(const Dog &src)
{
    std::cout << "Copy Dog constructor called" << std::endl;
    this->_type = src.getType();
    this->_brain = new Brain(*src._brain);
}
Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs.getType();
        delete (this->_brain);
        this->_brain = new Brain(*rhs._brain);
    }
    return (*this);
}
Dog::~Dog()
{
    delete (this->_brain);
    std::cout << "Default Dog Destructor called" << std::endl;
}
void Dog::makeSound() const
{
    std::cout << _type << ": wouf wouf wouf" << std::endl;
}

void Dog::setIdeas(const std::string &idea, int index)
{
    _brain->setIdeas(idea, index);
}
const std::string &Dog::getIdeas(int index) const
{
    return (_brain->getIdeas(index));
}

const Brain *Dog::getBrain() const
{
    return (_brain);
}

std::ostream &operator<<(std::ostream &ost, const Dog &rhs)
{
    ost << "Type: " << rhs.getType() << std::endl;
    if (rhs.getBrain())
        ost << *(rhs.getBrain());
    return (ost);
}