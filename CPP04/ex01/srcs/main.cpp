/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:06:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/05 15:20:03 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"
#include "../header/WrongCat.hpp"
#include "../header/Dog.hpp"

int main(void)
{

	const Animal *i = new Cat(); // i et j n'ont pas acces a set et get ideas car ils sont de type Animal et ne peuvent use que les fonctions heritees
	std::cout << std::endl;

	const Animal *j = new Dog();
	std::cout << std::endl;

	Cat *k = new Cat(); // peut use set et get ideas car directement de type cat
	std::cout << std::endl;
	Dog *l = new Dog(); // peut use set et get ideas car directement de type cat
	std::cout << std::endl;

	std::cout << *i << std::endl;
	std::cout << std::endl;
	std::cout << *j << std::endl;
	std::cout << std::endl;
	std::cout << *k << std::endl;
	std::cout << std::endl;
	std::cout << *l << std::endl;
	k->setIdeas("souris", 0);
	std::cout << k->getIdeas(1) << std::endl;

	delete i;
	delete j;
	delete k;
	return (0);
}