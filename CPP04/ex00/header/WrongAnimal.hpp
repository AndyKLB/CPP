/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:48:04 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 15:43:54 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_CLASS_HPP
# define WRONG_ANIMAL_CLASS_HPP
# include <iostream>

class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();
    
	std::string getType() const;
    
	virtual void makeSound() const;
    

  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &ost, const WrongAnimal &rhs);


#endif