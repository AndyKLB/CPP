/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:48:17 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/04 15:40:24 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_CLASS_HPP
# define WRONG_CAT_CLASS_HPP
# include <iostream>
# include "../header/WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &rhs);
	~WrongCat();
    
    
	void makeSound() const;
    

  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &ost, const WrongCat &rhs);


#endif