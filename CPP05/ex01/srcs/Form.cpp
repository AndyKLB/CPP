/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:15:02 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/23 17:46:14 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Form.hpp"

Form::Form() : _name("undefined"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExec(150)
{
    std::cout << "Default Form constructor called" << std::endl;
}
Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _requiredGradeToSign(gradeToSign), _requiredGradeToExec(gradeToExec)
{
    std::cout << "Setter Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw(TooLowGradeException());
    if (gradeToSign > 150 || gradeToExec > 150)
        throw(TooHighGradeException());
}
Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _requiredGradeToSign(src.getReqToSign()), _requiredGradeToExec(src.getReqToExec())
{
    std::cout << "Copy Form constructor called" << std::endl;
}
Form &Form::operator=(const Form &rhs)
{
    std::cout << "Operator Form constructor called" << std::endl;
    if (this != &rhs)
        this->_isSigned = rhs.getIsSigned();
    return (*this);
}
Form::~Form()
{
    std::cout << "Default Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return (_name);
}
bool Form::getIsSigned() const
{
    return (_isSigned);
}
int Form::getReqToSign() const
{
    return (_requiredGradeToSign);
}
int Form::getReqToExec() const
{
    return (_requiredGradeToExec);
}

const char *Form::TooHighGradeException::what() const throw()
{
    return ("Grade is too High");
}

const char *Form::TooLowGradeException::what() const throw()
{
    return ("Grade is too Low");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getReqToSign())
        throw(TooLowGradeException());
    _isSigned = true;
    std::cout << this->getName() << " has been signed" << std::endl;
}

std::ostream &operator<<(std::ostream &ost, const Form &rhs)
{
    ost << "Name: " << rhs.getName() << std::endl;
    ost << "Is signed: " << (rhs.getIsSigned()? "yes" : "no") << std::endl;
    ost << "Required grade to sign: " << rhs.getReqToSign() << std::endl;
    ost << "Required grade to exec: " << rhs.getReqToExec() << std::endl;
    return (ost);
}
