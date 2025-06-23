/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:27:36 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/23 17:51:22 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"

int main()
{
    try
    {
        Bureaucrat jack("Jack", 1);
        Bureaucrat russel("Russel", 50);
        Form formA("RC12", 49, 60);
        Form formB("RC15", 50, 80);

        jack.signForm(formA);
        jack.signForm(formB);
        russel.signForm(formA);
        russel.signForm(formB);
        // formA.beSigned(russel);
        std::cout << std::endl;

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}