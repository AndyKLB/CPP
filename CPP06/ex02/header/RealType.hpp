/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:28:47 by ankammer          #+#    #+#             */
/*   Updated: 2025/07/02 17:35:23 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TYPE_HPP_CLASS
#define REAL_TYPE_HPP_CLASS
#include "Base.hpp"

class RealType
{
public:
    Base *generate(void);
    void identify(Base *p);
    void identify(Base &p);
};

#endif
