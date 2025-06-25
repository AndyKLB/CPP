/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:27:36 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/25 13:21:51 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"

int main()
{
    std::srand(std::time(0));
    try
    {
        Bureaucrat Jack("jack", 1);
        Bureaucrat Russel("Russel", 150);
        std::cout << std::endl;
        PresidentialPardonForm pardon("Jones");
        std::cout << std::endl;
        
        std::cout << Jack;
        std::cout << Russel;
        std::cout << std::endl;
        
        std::cout << pardon;
        std::cout << std::endl;
        
        Jack.executeForm(pardon); // form not signed
        std::cout << std::endl;
        Russel.signForm(pardon); // cannot sign
        std::cout << std::endl;
        Jack.signForm(pardon); // can sign
        std::cout << std::endl;
        Jack.executeForm(pardon); // can execute
        std::cout << std::endl;
        
        RobotomyRequestForm robot("Dwayne");
        std::cout << std::endl;
        
        std::cout << robot;
        std::cout << std::endl;
        Russel.executeForm(robot); // cannot execute
        std::cout << std::endl;
        Jack.signForm(robot); // can sign
        std::cout << std::endl;
        Russel.executeForm(robot); // cannot execute
        std::cout << std::endl;
        Jack.executeForm(robot); // can execute
        std::cout << std::endl;
        
        ShrubberyCreationForm shrub("arbuste");
        std::cout << std::endl;
        std::cout << shrub;
        std::cout << std::endl;
        Jack.signForm(shrub); // can sign
        std::cout << std::endl;
        Russel.executeForm(shrub); // cannot exec
        std::cout << std::endl;
        Jack.signForm(shrub); // already signed
        std::cout << std::endl;
        Jack.executeForm(shrub); // can exec        
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}