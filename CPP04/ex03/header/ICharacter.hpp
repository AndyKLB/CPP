/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:26 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/11 16:08:34 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_CLASS_HPP
#define ICHARACTER_CLASS_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
class AMateria;


class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
    virtual AMateria *getMateria(int idx) = 0;
    
};

#endif
