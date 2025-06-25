/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:29:15 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/25 13:23:52 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("undefined", 145, 137)
{
    std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137)
{
    std::cout << "Set target ShrubberyCreationForm constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    std::cout << "Operator ShrubberyCreationForm constructor called" << std::endl;
    if (this != &rhs)
        AForm::operator=(rhs);
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Default ShrubberyCreationForm detructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    this->checkRightToExec(executor);
    std::ofstream file((this->getName() + "_shrubbery").c_str());
    if (!file)
    {
        std::cerr << "Error creating file " << this->getName() << "_shrubbery" << std::endl;
        return;
    }
    file << "\033[32m"; 
    file << "    *\n";
    file << "   ***\n";
    file << "  *****\n";
    file << " *******\n";
    file << "   |||\n";
    file << "\033[0m";

    file.close();
    std::cout << "shrubbery tree created at " << this->getName() << "_shrubbery" << std::endl;
}