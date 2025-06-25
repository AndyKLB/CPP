/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:27:36 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/25 17:44:50 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/Intern.hpp"

int main()
{
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    Bureaucrat jack("jack", 1);
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "                                                             |" << std::endl;
    AForm *robot;
    robot = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << std::endl;
    if (robot)
    {
        jack.signForm(*robot);
        jack.executeForm(*robot);
    }
    std::cout << "                                                             |" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "                                                             |" << std::endl;
    AForm *pardon;
    pardon = someRandomIntern.makeForm("presidential pardon", "Jones");
    std::cout << std::endl;
    if (pardon)
    {
        jack.signForm(*pardon);
        jack.executeForm(*pardon);
    }
    std::cout << "                                                             |" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "                                                             |" << std::endl;
    AForm *shrub;
    shrub = someRandomIntern.makeForm("shrubbery creation", "arbuste");
    std::cout << std::endl;
    if (shrub)
    {
        jack.signForm(*shrub);
        jack.executeForm(*shrub);
    }
    std::cout << "                                                             |" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "                                                             |" << std::endl;
    AForm *invalid;
    invalid = someRandomIntern.makeForm("invalid form", "arbuste");
    std::cout << std::endl;
    if (invalid)
    {
        jack.signForm(*invalid);
        jack.executeForm(*invalid);
    }
    std::cout << "                                                             |" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    delete robot;
    std::cout << std::endl;
    delete pardon;
    std::cout << std::endl;
    delete shrub;
    std::cout << std::endl;
    delete invalid;
}