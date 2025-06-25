/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:04:32 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/25 17:20:14 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
#define INTERN_CLASS_HPP

#include "AForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &src);
    Intern &operator=(const Intern &rhs);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &formTarget) const;

private:
    AForm *makePresidentialForm(const std::string &target) const;
    AForm *makeRobotomy(const std::string &target) const;
    AForm *makeShrubberyForm(const std::string &target) const;
};

#endif