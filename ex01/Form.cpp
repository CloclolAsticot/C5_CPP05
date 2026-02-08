/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:34:12 by csavreux          #+#    #+#             */
/*   Updated: 2026/02/08 18:48:11 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("generic_form"), _isSigned(false), _requiredSignGrade(1), _requiredExecuteGrade(1)
{
}

Form::Form(const std::string& name, const int requiredSignGrade, const int requiredExecuteGrade) : _name(name), _isSigned(false), _requiredSignGrade(requiredSignGrade), _requiredExecuteGrade(requiredExecuteGrade)
{
    if (requiredSignGrade < 1 || requiredExecuteGrade < 1)
        throw GradeTooHighException();
    else if (requiredSignGrade > 150 || requiredExecuteGrade > 150)
        throw GradeTooLowException();
}
Form::Form(const Form& other) : _name(other._name), _isSigned(false), _requiredSignGrade(other._requiredSignGrade), _requiredExecuteGrade(other._requiredExecuteGrade)
{
}
        
Form::~Form()
{
}

Form&               Form::operator=(const Form& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

const std::string&  Form::getName() const
{
    return (this->_name);
}

bool                Form::getIsSigned() const
{
    return (this->_isSigned);
}

int                 Form::getRequiredSignGrade() const
{
    return (this->_requiredSignGrade);
}

int                 Form::getRequiredExecuteGrade() const
{
    return (this->_requiredExecuteGrade);
}

void                Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->_isSigned == true)
        throw AlreadySignedException();
    else if (bureaucrat.getGrade() > this->_requiredSignGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

const char*         Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char*         Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char*         Form::AlreadySignedException::what() const throw()
{
    return ("Form is already signed!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", form signed : ";
    if (form.getIsSigned() == true)
        os << "yes, grade to sign ";
    else
        os << "no, grade to sign ";
    os << form.getRequiredSignGrade() << ", grade to execute : " << form.getRequiredExecuteGrade() << "." << std::endl;
    return (os);
}
