/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:50:41 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/05 14:01:34 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
#define BRAIN_CLASS_HPP
#include <iostream>
#include <string>

class Brain
{
public:
    Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &rhs);
    ~Brain();

    void setIdeas(const std::string &idea, int index);
    const std::string &getIdeas(int index) const;

private:
    std::string _ideas[100];
};

std::ostream &operator<<(std::ostream &ost, const Brain &rhs);

#endif