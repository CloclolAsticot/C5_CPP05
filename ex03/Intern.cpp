/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:12:22 by csavreux          #+#    #+#             */
/*   Updated: 2026/02/08 18:42:52 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
}
        
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

static AForm* makeShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* makePardon(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm*    Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formTypes[3] = {"shrubbery creation",
                                "robotomy request",
                                "presidential pardon"};

    AForm* (*formCreations[3])(const std::string&) =   {&makeShrubbery,
                                                        &makeRobotomy,
                                                        &makePardon};
        
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formTypes[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (formCreations[i](target));
        }
    }
    std::cout << formName << " form doesn't exist." << std::endl;
    return (NULL);
}
