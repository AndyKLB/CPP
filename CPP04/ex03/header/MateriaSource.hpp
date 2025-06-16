/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:32 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 14:44:09 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
#define MATERIASOURCE_CLASS_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    ~MateriaSource();

    const MateriaSource &operator=(const MateriaSource &rhs);

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);

    void printMateria();

private:
    AMateria *_stock[4];
};

#endif