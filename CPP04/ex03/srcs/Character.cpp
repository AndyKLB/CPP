/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:44:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 16:11:28 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Character.hpp"

Character::Character() : _name("undefined")
{
    std::cout << "Default Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _items[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Name init Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _items[i] = NULL;
}

Character::Character(const Character &src)
{
    std::cout << "Copy Character constructor called" << std::endl;
    this->_name = src.getName();
    for (int i = 0; i < 4; i++)
    {
        if (src._items[i])
            this->_items[i] = src._items[i]->clone();
        else
            _items[i] = NULL;
    }
}
Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_items[i])
            delete (this->_items[i]);
    }
    std::cout << "Default Character destructor called" << std::endl;
}
const Character &Character::operator=(const Character &rhs)
{
    std::cout << "Operator constructor called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        for (int i = 0; i < 4; i++)
        {
            if (_items[i])
                delete (_items[i]);
            if (rhs._items[i])
                this->_items[i] = rhs._items[i]->clone();
            else
                this->_items[i] = NULL;
        }
    }

    return (*this);
}

std::string const &Character::getName() const
{
    return (_name);
}
void Character::equip(AMateria *m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!this->_items[i])
            {
                std::cout << this->getName() << " equip " << m->getType() << " materia" << std::endl;
                this->_items[i] = m;
                return;
            }
        }
        std::cout << this->getName() << " cannot equip " << m->getType() << " materia, inventory is full" << std::endl;
    }
    std::cout << "materia error" << std::endl;
}
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->_items[idx])
        {
            std::cout << this->getName() << " unequip " << _items[idx]->getType() << " materia" << std::endl;
            _items[idx] = NULL;
        }
        else
            std::cout << "No materia available at this slot" << std::endl;
    }
    else
        std::cout << "invalid slot provide between 0 & 3" << std::endl;
}
void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->_items[idx])
        {
            std::cout << this->getName() << ": ";
            this->_items[idx]->use(target);
        }
        else
            std::cout << this->getName() << " has no materia at this slot" << std::endl;
    }
    else
        std::cout << "error invalid slot provide idx between 0 & 3" << std::endl;
}

AMateria *Character::getMateria(int idx)
{
    if (!this->_items[idx])
        std::cout << "No materia available at this slot" << std::endl;
    else
        std::cout << "Materia of type " << this->_items[idx]->getType() << " at this slot" << std::endl;
    return (this->_items[idx]);
}
