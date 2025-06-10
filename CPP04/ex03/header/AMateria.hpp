/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:19 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/10 15:08:40 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_HPP
#define AMATERIA_CLASS_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{

public:
    AMateria();
    AMateria(const std::string &type);
    AMateria(const AMateria &src);
    const AMateria &operator=(const AMateria &rhs);
    virtual ~AMateria();

    const std::string &getType() const;    // Returns the materia type
    void setType(const std::string &type); // Set the materia type

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

protected:
    std::string _type;
};

#endif