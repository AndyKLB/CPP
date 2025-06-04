/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:06:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 15:42:56 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/Cat.hpp"
#include "../header/WrongCat.hpp"
#include "../header/Dog.hpp"

int main(void)
{
	// const Animal *animal = new Animal();
	// const Animal *cat = new Cat();
	// const Animal *dog = new Dog();
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	// std::cout << *animal << " " << std::endl;
	// std::cout << *cat << " " << std::endl;
	// std::cout << *dog << " " << std::endl;
	std::cout << *wrongAnimal << " " << std::endl;
	std::cout << *wrongCat << " " << std::endl;
	// animal->makeSound();
	// cat->makeSound(); // will output the cat sound!
	// dog->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	// delete animal;
	// delete cat;
	// delete dog;
	delete wrongAnimal;
	delete wrongCat;
	return (0);
}