/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:00:11 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 16:08:49 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Character.hpp"
#include "../header/Cure.hpp"
#include "../header/Ice.hpp"
#include "../header/Thunder.hpp"
#include "../header/MateriaSource.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    std::cout << std::endl;

    IMateriaSource *copy = new MateriaSource();
    std::cout << std::endl;

    // MateriaSource *src = new MateriaSource();
    // std::cout << std::endl;

    // MateriaSource *copy = new MateriaSource();
    // std::cout << std::endl;

    src->learnMateria(new Ice());
    std::cout << std::endl;

    src->learnMateria(new Cure());
    std::cout << std::endl;

    *copy = *src;
    std::cout << std::endl;

    copy->learnMateria(new Thunder());
    std::cout << std::endl;

    src->printMateria();
    std::cout << std::endl;

    copy->printMateria();
    std::cout << std::endl;

    ICharacter *me = new Character("me");
    std::cout << std::endl;

    AMateria *tmp;

    tmp = src->createMateria("ice");
    std::cout << std::endl;

    me->equip(tmp);
    std::cout << std::endl;

    tmp = src->createMateria("thunder");
    tmp = src->createMateria("cure");
    std::cout << std::endl;

    me->equip(tmp);
    std::cout << std::endl;

    tmp = copy->createMateria("thunder");
    std::cout << std::endl;

    me->equip(tmp);
    std::cout << std::endl;

    ICharacter *bob = new Character("bob");
    std::cout << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    std::cout << std::endl;

    AMateria *garbage = me->getMateria(2);
    AMateria *secondGarbage = me->getMateria(3);
    std::cout << std::endl;
    
    me->unequip(2);
    me->unequip(3);
    std::cout << std::endl;

    delete bob;
    std::cout << std::endl;

    delete me;
    std::cout << std::endl;

    delete src;
    std::cout << std::endl;

    delete copy;
    std::cout << std::endl;

    delete garbage;
    delete secondGarbage;
    return 0;
}
