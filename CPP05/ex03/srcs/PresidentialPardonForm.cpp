/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:29:09 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/25 14:05:08 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("undefined", 25, 137)
{
    std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 137)
{
    std::cout << "Set target name PresidentialPardonForm constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    std::cout << "Operator PresidentialPardonForm constructor called" << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Default PresidentialPardonForm detructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    this->checkRightToExec(executor);
    std::cout << executor.getName() << " executed form: " << this->getName() << std::endl;
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}