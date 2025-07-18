/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:32:44 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/23 13:46:35 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_CLASS
#define BUREAUCRAT_HPP_CLASS
#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <stdio.h>
#include <limits>

class Bureaucrat
{
public:
    class TooHighGradeException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade is too high");
        }
    };
    class TooLowGradeException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade is too low");
        }
    };

    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &rhs);

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &ost, const Bureaucrat &rhs);

#endif