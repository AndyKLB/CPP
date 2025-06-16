/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:33:18 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 13:34:35 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THUNDER_CLASS_HPP
#define THUNDER_CLASS_HPP
#include "../header/AMateria.hpp"

class Thunder : public AMateria
{
public:
    Thunder();
    Thunder(const Thunder &src);
    ~Thunder();
    
    const Thunder &operator=(const Thunder &rhs);
    
    AMateria *clone() const;
    void use(ICharacter &target);

private:
};

#endif