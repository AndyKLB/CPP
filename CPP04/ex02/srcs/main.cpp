/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:06:42 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 16:01:06 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"
#include "../header/WrongCat.hpp"
#include "../header/Dog.hpp"

int main(void)
{

	// Animal *forbid = new Animal;
	// forbid->makeSound();
	AAnimal *authorized = new Cat;
	std::cout << std::endl;
	std::cout << *authorized << std::endl;
	std::cout << std::endl;
	Cat *kitkat = new Cat;
	std::cout << std::endl;
	std::cout << *kitkat << std::endl;
	std::cout << std::endl;

	delete (authorized);
	delete (kitkat);

	return (0);
}