/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:32 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/11 15:36:02 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_stock[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &src)
{
    std::cout << "Copy MateriaSource constructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (src._stock[i])
            this->_stock[i] = src._stock[i]->clone();
        else
            this->_stock[i] = NULL;
    }
}
MateriaSource::~MateriaSource()
{
    std::cout << "Default MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_stock[i])
        {
            delete (this->_stock[i]);
            this->_stock[i] = NULL;
        }
    }
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_stock[i])
                delete (this->_stock[i]);
            if (rhs._stock[i])
                this->_stock[i] = rhs._stock[i]->clone();
            else
                this->_stock[i] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!this->_stock[i])
        {
            this->_stock[i] = m->clone();
            delete (m);
            std::cout << "Materia type " << _stock[i]->getType() << " learned" << std::endl;
            return;
        }
    }

    std::cout << "stock is full impossible to learn new materia" << std::endl;
    delete (m);
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_stock[i] && this->_stock[i]->getType() == type)
            return (this->_stock[i]->clone());
    }
    std::cout << "Unknown materia type, impossible to create it!" << std::endl;
    return (NULL);
}