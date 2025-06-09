/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:46:01 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/09 15:28:42 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP
#include "../header/AAnimal.hpp"

class Cat : public AAnimal
{
public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();

    virtual void makeSound() const;
    void setIdeas(const std::string &idea, int index);
    const std::string &getIdeas(int index) const;
    const Brain *getBrain() const;
  

private:
    Brain *_brain;
};

std::ostream &operator<<(std::ostream &ost, const Cat &rhs);

#endif