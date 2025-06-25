/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:14:56 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/24 16:55:10 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
#define AFORM_CLASS_HPP
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
    class TooLowGradeException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class TooHighGradeException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExec);
    AForm(const AForm &src);
    AForm &operator=(const AForm &rhs);
    virtual ~AForm();

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;

    std::string getName() const;
    bool getIsSigned() const;
    int getReqToSign() const;
    int getReqToExec() const;

protected:
    void checkRightToExec(const Bureaucrat &executor) const;

private:
    const std::string _name;
    bool _isSigned;
    const int _requiredGradeToSign;
    const int _requiredGradeToExec;
};

std::ostream &operator<<(std::ostream &ost, const AForm &rhs);

#endif