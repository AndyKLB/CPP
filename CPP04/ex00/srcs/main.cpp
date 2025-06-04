/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:06:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 16:44:41 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/Cat.hpp"
#include "../header/WrongCat.hpp"
#include "../header/Dog.hpp"

int main(void)
{
	const Animal *animal = new Animal();
	std::cout << std::endl;

	const Animal *cat = new Cat();
	std::cout << std::endl;

	const Animal *dog = new Dog();
	std::cout << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	std::cout << std::endl;

	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << *animal << " " << std::endl;
	std::cout << *cat << " " << std::endl;
	std::cout << *dog << " " << std::endl;
	std::cout << *wrongAnimal << " " << std::endl;
	std::cout << *wrongCat << " " << std::endl;
	animal->makeSound();
	cat->makeSound(); // will output the cat sound!
	dog->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	delete animal;
	std::cout << std::endl;

	delete cat;
	std::cout << std::endl;
	delete dog;
	std::cout << std::endl;
	delete wrongAnimal;
	std::cout << std::endl;
	delete wrongCat;
	return (0);
}