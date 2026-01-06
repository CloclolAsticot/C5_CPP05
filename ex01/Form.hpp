/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:34:09 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/06 16:14:49 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _requiredSignGrade;
        const int           _requiredExecuteGrade;

    public:
        // Constructors / Destructors
        Form();
        Form(const std::string& name, const int requiredSignGrade, const int requiredExecuteGrade);
        Form(const Form& other);
        ~Form();

        Form& operator=(const Form& other);

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
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form&);

#endif