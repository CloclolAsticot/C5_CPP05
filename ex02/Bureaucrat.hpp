/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:10:22 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/06 17:09:31 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class AForm;

class Bureaucrat 
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        // Constructors / Destructors
        Bureaucrat();
        Bureaucrat(const std::string& name, const int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);

        // Getters
        const std::string&  getName() const;
        int                 getGrade() const;

        // Other member functions
        void                incrementGrade();
        void                decrementGrade();

        void                signForm(AForm& form);

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat&);

#endif