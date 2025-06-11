/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:24 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/11 15:06:30 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_HPP
#define CURE_CLASS_HPP
#include "../header/AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &src);
    const Cure & operator=(const Cure &rhs);
    ~Cure();
    

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);

private:
};
#endif