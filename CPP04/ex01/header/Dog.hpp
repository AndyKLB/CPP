/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:45:50 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/05 14:19:58 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    ~Dog();

    virtual void makeSound() const;
    void setIdeas(const std::string &idea, int index);
    const std::string &getIdeas(int index) const;

private:
    Brain *_brain;
};

std::ostream &operator<<(std::ostream &ost, const Dog &rhs);