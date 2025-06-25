/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:04:18 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/25 17:20:43 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor called" << std::endl;
}
Intern::Intern(const Intern &src)
{
    std::cout << "Copy Intern constructor called" << std::endl;
    (void)src;
}
Intern &Intern::operator=(const Intern &rhs)
{
    std::cout << "Operator Intern constructor called" << std::endl;
    (void)rhs;
    return (*this);
}
Intern::~Intern()
{
    std::cout << "Default Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
    std::string formsTab[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(Intern::*FormFunctionTab[])(const std::string &target) const = {
        &Intern::makePresidentialForm,
        &Intern::makeRobotomy,
        &Intern::makeShrubberyForm};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formsTab[i])
        {
            std::cout << "Intern creates form: " << formName << std::endl;
            return ((this->*FormFunctionTab[i])(formTarget));
        }
    }
    std::cerr << "Provided form name does not exist provide a valid name" << std::endl;
    return (0);
}

AForm *Intern::makePresidentialForm(const std::string &target) const
{
    return (new PresidentialPardonForm(target));
}
AForm *Intern::makeRobotomy(const std::string &target) const
{
    return (new RobotomyRequestForm(target));
}
AForm *Intern::makeShrubberyForm(const std::string &target) const
{
    return (new ShrubberyCreationForm(target));
}