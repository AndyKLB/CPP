/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:15:02 by ankammer          #+#    #+#             */
/*   Updated: 2025/06/24 12:23:58 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"

AForm::AForm() : _name("undefined"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExec(150)
{
    std::cout << "Default AForm constructor called" << std::endl;
}
AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _requiredGradeToSign(gradeToSign), _requiredGradeToExec(gradeToExec)
{
    std::cout << "Setter AForm constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw(TooLowGradeException());
    if (gradeToSign > 150 || gradeToExec > 150)
        throw(TooHighGradeException());
}
AForm::AForm(const AForm &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _requiredGradeToSign(src.getReqToSign()), _requiredGradeToExec(src.getReqToExec())
{
    std::cout << "Copy AForm constructor called" << std::endl;
}
AForm &AForm::operator=(const AForm &rhs)
{
    std::cout << "Operator AForm constructor called" << std::endl;
    if (this != &rhs)
        this->_isSigned = rhs.getIsSigned();
    return (*this);
}
AForm::~AForm()
{
    std::cout << "Default AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return (_name);
}
bool AForm::getIsSigned() const
{
    return (_isSigned);
}
int AForm::getReqToSign() const
{
    return (_requiredGradeToSign);
}
int AForm::getReqToExec() const
{
    return (_requiredGradeToExec);
}

const char *AForm::TooHighGradeException::what() const throw()
{
    return ("Grade is too High");
}

const char *AForm::TooLowGradeException::what() const throw()
{
    return ("Grade is too Low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed!");
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getReqToSign())
        throw(TooLowGradeException());
    if (_isSigned)
    {
        std::cout << bureaucrat.getName() << " doesn't need to sign because form: " << this->getName() << " has already been signed" << std::endl;
        return;
    }
    _isSigned = true;
    std::cout << "Form: " << this->getName() << " has been signed, " << bureaucrat.getName() << " signed " << this->getName() << std::endl;
}

void AForm::checkRightToExec(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
        throw(FormNotSignedException());
    if (executor.getGrade() > this->getReqToExec())
        throw(TooLowGradeException());
}

std::ostream &operator<<(std::ostream &ost, const AForm &rhs)
{
    ost << "Name: " << rhs.getName() << std::endl;
    ost << "Is signed: " << (rhs.getIsSigned() ? "yes" : "no") << std::endl;
    ost << "Required grade to sign: " << rhs.getReqToSign() << std::endl;
    ost << "Required grade to exec: " << rhs.getReqToExec() << std::endl;
    return (ost);
}
