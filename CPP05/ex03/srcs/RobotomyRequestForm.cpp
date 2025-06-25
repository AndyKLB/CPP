/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:29:12 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/25 12:58:15 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("undefined", 72, 45)
{
    std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45)
{
    std::cout << "Set target RobotomyRequestForm constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    std::cout << "Operator RobotomyRequestForm constructor called" << std::endl;

    if (this != &rhs)
        AForm::operator=(rhs);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Default RobotomyRequestForm detructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    this->checkRightToExec(executor);
    std::cout << executor.getName() << " executed form: " << this->getName() << std::endl;
    std::cout << "*|\\|*drilling noises*|\\|*" << std::endl;
    if (std::rand() % 2)
        std::cout << this->getName() << " has been robotomized succesfully!" << std::endl;
    else
        std::cout << this->getName() << " failed to be robotomized!" << std::endl;
}