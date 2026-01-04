/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:10:20 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/04 16:17:46 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("generic_bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

const std::string&  Bureaucrat::getName() const
{
    return (this->_name);
}

int                 Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void                Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
}


void                Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
}

const char*         Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char*         Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return (os);
}
