/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:27:36 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/18 16:57:43 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

bool notAlpha(const std::string name)
{
    for (int i = 0; name[i]; i++)
    {
        if (!isalpha(name[i]))
            return (1);
    }
    return (0);
}

int main()
{
    int grade;
    std::string gradeStr;
    std::string name;
    std::stringstream ss;

    while (1)
    {
        std::cout << "what's your bureaucrat name? ";
        getline(std::cin >> std::ws, name);
        if (std::cin.eof())
            return (0);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error with getline try again";
            continue;
        }
        if (notAlpha(name))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error with input provide only alpha character";
            continue;
        }
        while (1)
        {
            std::cout << "what's your bureaucrat grade? ";
            getline(std::cin >> std::ws, gradeStr);
            ss.clear();
            ss.str("");
            ss << gradeStr;
            ss >> grade;
            if (std::cin.eof())
                return (0);
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error with getline try again";
                continue;
            }
            if (ss.fail())
            {
                ss.clear();
                ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error with input provide only numbers";
                continue;
            }
            break;
        }
        break;
    }
    try
    {
        Bureaucrat employe("jack", 150);
        
    }
    catch
    {
    }
}