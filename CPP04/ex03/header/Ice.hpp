/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:22 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/11 15:06:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
#define ICE_CLASS_HPP
#include "../header/AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &src);
    ~Ice();
    
    const Ice &operator=(const Ice &rhs);
    
    AMateria *clone() const;
    void use(ICharacter &target);

private:
};

#endif