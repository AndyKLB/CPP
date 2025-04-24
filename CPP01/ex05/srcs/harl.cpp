/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:33 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/24 13:37:22 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}

void Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do !" << std::endl;
}
void Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::_error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*functionPtr[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    std::string levelToCompare[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (!levelToCompare[i].compare(level))
        {
            (this->*functionPtr[i])();
            return;
        }
    }
    std::cout << "error: provide a correct level : DEBUG | INFO | WARNING | ERROR" << std::endl;
}