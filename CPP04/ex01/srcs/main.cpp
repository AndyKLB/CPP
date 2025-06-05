/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:06:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/05 17:21:31 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"
#include "../header/WrongCat.hpp"
#include "../header/Dog.hpp"

int main(void)
{
	{
		const Animal *i = new Cat(); // i et j n'ont pas acces a set et get ideas car ils sont de type Animal et ne peuvent use que les fonctions heritees
		std::cout << std::endl;

		const Animal *j = new Dog();
		std::cout << std::endl;

		Dog *l = new Dog(); // peut use set et get ideas car directement de type cat
		std::cout << std::endl;

		std::cout << *i << std::endl;
		std::cout << std::endl;

		std::cout << *j << std::endl;
		std::cout << std::endl;

		l->setIdeas("niku", 0);
		std::cout << *l << std::endl;
		std::cout << std::endl;

		delete i;
		delete j;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

	}
	{
		Cat *original = new Cat();
		original->setIdeas(" une souris ", 0);
		std::cout << std::endl;

		Cat *copy = new Cat(*original);
		std::cout << std::endl;

		std::cout << "adress original = " << original << std::endl;
		std::cout << "adress copy = " << copy << std::endl;
		std::cout << std::endl;

		std::cout << "adress brain original = " << original->getBrain() << std::endl;
		std::cout << "adress brain copy = " << copy->getBrain() << std::endl;
		std::cout << std::endl;

		std::cout << "original: " << *original;
		std::cout << "copy: " << *copy;
		std::cout << std::endl;

		copy->setIdeas(" deux sourissssssssssss ", 0);
		std::cout << "original: " << *original;
		std::cout << "copy: " << *copy;
		std::cout << std::endl;

		delete original;
		delete copy;
	}
	return (0);
}