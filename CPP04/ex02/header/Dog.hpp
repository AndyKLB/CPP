/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:45:50 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/09 15:28:48 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AAnimal.hpp"

class Dog : public AAnimal
{
public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    ~Dog();

    virtual void makeSound() const;
    void setIdeas(const std::string &idea, int index);
    const std::string &getIdeas(int index) const;
    const Brain *getBrain() const;


private:
    Brain *_brain;
};

std::ostream &operator<<(std::ostream &ost, const Dog &rhs);