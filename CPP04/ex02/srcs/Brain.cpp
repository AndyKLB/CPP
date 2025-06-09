/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:50:36 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/05 16:48:42 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain constructor called" << std::endl;
}
Brain::Brain(const Brain &src)
{
    std::cout << "Copy Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = src._ideas[i];
}
Brain &Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = rhs._ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Default Brain destructor called" << std::endl;
}
void Brain::setIdeas(const std::string &idea, int index)
{
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}
const std::string &Brain::getIdeas(int index) const
{
    static const std::string empty = "";
    if (index >= 0 && index < 100)
        return (_ideas[index]);
    return (empty);
}

std::ostream &operator<<(std::ostream &ost, const Brain &rhs)
{
    for (int i = 0; i < 100; i++)
    {
        const std::string &idea = rhs.getIdeas(i);
        if (!idea.empty())
            ost << "idea [" << i << "]" << rhs.getIdeas(i) << std::endl;
    }
    return (ost);
}
