/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:10:39 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/03 13:40:44 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
  public:
	Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &rhs);
	~Animal();
    
	std::string getType() const;
    
	virtual void makeSound() const = 0;
    

  protected:
	std::string type;
};

std::ostream operator<<(std::ostreanm &ost, const animal &rhs);


#endif