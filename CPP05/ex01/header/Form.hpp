/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:14:56 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/23 15:50:18 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
#define FORM_CLASS_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    class TooLowGradeException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class TooHighGradeException : std::exception
    {
    public:
        const char *what() const throw();
    };

    Form();
    Form(std::string name, int gradeToSign, int gradeToExec);
    Form(const Form &src);
    Form &operator=(const Form &rhs);
    ~Form();

    void beSigned(const Bureaucrat &bureaucrat);

    std::string getName() const;
    bool getIsSigned() const;
    int getReqToSign() const;
    int getReqToExec() const;

private:
    const std::string _name;
    bool _isSigned;
    const int _requiredGradeToSign;
    const int _requiredGradeToExec;
};

std::ostream &operator<<(std::ostream &ost, const Form &rhs);

#endif