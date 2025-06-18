/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:30:19 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/18 16:24:15 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("undefined"), _grade(150)
{
    std::cout << "Default bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << "Set name and grade bureaucrat constructor called" << std::endl;
    if (grade < 0)
        throw(Bureaucrat::TooHighGradeException());
    else if (grade > 150)
        throw(Bureaucrat::TooLowGradeException());
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade())
{
    std::cout << "Copy bureaucrat constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Default bureaucrat destructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    std::cout << "Operator bureaucrat constructor called" << std::endl;
    if (this != &rhs)
        this->_grade = rhs.getGrade();
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return (_name);
}
int Bureaucrat::getGrade() const
{
    return (_grade);
}

std::ostream &operator<<(std::ostream &ost, const Bureaucrat &rhs)
{
    ost << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
}
