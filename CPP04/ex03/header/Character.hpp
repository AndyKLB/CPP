/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:44:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/10 17:04:07 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP
#include "../header/ICharacter.hpp"

class Character : Character
{
public:
    Character();
    Character(std::string name);
    Character(const Character &src);
    ~Character();

    const Character &operator=(const Character &rhs);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:
    AMateria *_items[4];
    std::string _name;
};

#endif