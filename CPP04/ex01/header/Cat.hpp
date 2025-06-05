/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:46:01 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/05 14:14:26 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP
#include "../header/Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();

    virtual void makeSound() const;
    void setIdeas(const std::string &idea, int index);
    const std::string &getIdeas(int index) const;
  

private:
    Brain *_brain;
};

std::ostream &operator<<(std::ostream &ost, Cat &rhs);

#endif