/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:10:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/16 15:56:39 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP
# include <iostream>
#include "../header/Brain.hpp"

class AAnimal
{
  public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &rhs);
	virtual ~AAnimal();
    
	std::string getType() const;
    
	virtual void makeSound() const = 0;
    

  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &ost, const AAnimal &rhs);


void makeSpeak(const AAnimal & animal);


#endif