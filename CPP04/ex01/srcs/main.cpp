/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:06:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:42:23 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"
#include "../header/WrongCat.hpp"
#include "../header/Dog.hpp"

int main(void)
{
	{
		Animal *horde[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
			{
				horde[i] = new Dog;
				std::cout << std::endl;
			}
			else
			{
				horde[i] = new Cat;
				std::cout << std::endl;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			delete horde[i];
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		const Animal *aCat = new Cat; // i et j n'ont pas acces a set et get ideas car ils sont de type Animal et ne peuvent use que les fonctions heritees
		std::cout << std::endl;

		const Animal *aDog = new Dog;
		std::cout << std::endl;

		Dog *dog = new Dog; // peut use set et get ideas car directement de type cat
		std::cout << std::endl;

		std::cout << *aCat << std::endl;
		std::cout << std::endl;

		std::cout << *aDog << std::endl;
		std::cout << std::endl;

		dog->setIdeas("meat", 0);
		std::cout << *dog << std::endl;
		std::cout << std::endl;

		delete aCat;
		std::cout << std::endl;
		delete aDog;
		std::cout << std::endl;
		delete dog;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		Cat *original = new Cat;
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

		std::cout << "----------BEFORE----------" << std::endl;
		std::cout << "original: " << *original;
		std::cout << std::endl;
		std::cout << "copy: " << *copy;
		std::cout << "--------------------------" << std::endl;
		std::cout << std::endl;
		
		copy->setIdeas(" deux souris", 0);
		
		std::cout << "----------AFTER-----------" << std::endl;
		std::cout << "original: " << *original;
		std::cout << std::endl;
		std::cout << "copy: " << *copy;
		std::cout << "--------------------------" << std::endl;
		std::cout << std::endl;

		delete original;
		delete copy;
	}
	return (0);
}