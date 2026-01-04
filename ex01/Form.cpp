/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:34:12 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/04 17:25:50 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("generic_form"), _isSigned(false), _requiredSignGrade(1), _requiredExecuteGrade(1)
{
}

Form::Form(const std::string& name, const int requiredSignGrade, const int requiredExecuteGrade) : _name(name), _isSigned(false), _requiredSignGrade(requiredSignGrade), _requiredExecuteGrade(requiredExecuteGrade)
{
}
Form::Form(const Form& other)
{
    
}
        
Form::~Form()
{
}

        Form& operator=(Form& other);

        // Getters
        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getRequiredSignGrade() const;
        int                 getRequiredExecuteGrade() const;

        // Other member functions
        void                beSigned(const Bureaucrat& bureaucrat);

        // Exceptions
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };