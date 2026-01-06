/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:34:09 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/06 18:24:32 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _requiredSignGrade;
        const int           _requiredExecuteGrade;

    protected:
        virtual void executeAction() const = 0;
        
    public:
        // Constructors / Destructors
        AForm();
        AForm(const std::string& name, const int requiredSignGrade, const int requiredExecuteGrade);
        AForm(const AForm& other);
        ~AForm();

        AForm& operator=(const AForm& other);

        // Getters
        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getRequiredSignGrade() const;
        int                 getRequiredExecuteGrade() const;

        // Other member functions
        void                beSigned(const Bureaucrat& bureaucrat);
        void                execute(Bureaucrat const & executor);       // will validate grades + call executeAction

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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm&);

#endif