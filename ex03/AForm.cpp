/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:34:12 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/10 21:52:23 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("generic_form"), _isSigned(false), _requiredSignGrade(1), _requiredExecuteGrade(1)
{
}

AForm::AForm(const std::string& name, const int requiredSignGrade, const int requiredExecuteGrade) : _name(name), _isSigned(false), _requiredSignGrade(requiredSignGrade), _requiredExecuteGrade(requiredExecuteGrade)
{
    if (requiredSignGrade < 1 || requiredExecuteGrade < 1)
        throw GradeTooHighException();
    else if (requiredSignGrade > 150 || requiredExecuteGrade > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other) : _name(other._name), _isSigned(false), _requiredSignGrade(other._requiredSignGrade), _requiredExecuteGrade(other._requiredExecuteGrade)
{
}
        
AForm::~AForm()
{
}

AForm&               AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

const std::string&  AForm::getName() const
{
    return (this->_name);
}

bool                AForm::getIsSigned() const
{
    return (this->_isSigned);
}

int                 AForm::getRequiredSignGrade() const
{
    return (this->_requiredSignGrade);
}

int                 AForm::getRequiredExecuteGrade() const
{
    return (this->_requiredExecuteGrade);
}

void                AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->_isSigned == true)
        throw AlreadySignedException();
    else if (bureaucrat.getGrade() > this->_requiredSignGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

void                AForm::execute(Bureaucrat const& executor) const
{
    if (this->_isSigned == false)
        throw NotSignedException();
    else if (executor.getGrade() > this->_requiredExecuteGrade)
        throw GradeTooLowException();
    executeAction(); 
}

const char*         AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char*         AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char*         AForm::AlreadySignedException::what() const throw()
{
    return ("Form is already signed!");
}

const char*         AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << ", form signed : ";
    if (form.getIsSigned() == true)
        os << "yes, grade to sign ";
    else
        os << "no, grade to sign ";
    os << form.getRequiredSignGrade() << ", grade to execute : " << form.getRequiredExecuteGrade() << "." << std::endl;
    return (os);
}
