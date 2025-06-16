/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:10:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:56:14 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP
# include <iostream>
#include "../header/Brain.hpp"

class Animal
{
  public:
	Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();
    
	std::string getType() const;
    
	virtual void makeSound() const;
    

  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &ost, const Animal &rhs);

void makeSpeak(const Animal & animal);


#endif