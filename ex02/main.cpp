/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:10:26 by csavreux          #+#    #+#             */
/*   Updated: 2026/02/08 18:46:10 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>


int main()
{
    srand(time(NULL)); //generates the seed used by rand() for the Robotomization request form
    
    {
        try {
            Bureaucrat bob = Bureaucrat("bob", 1);
            
            std::cout << "\n=== SHRUBBERY FORM TEST ===" << std::endl;
            ShrubberyCreationForm shrubbery = ShrubberyCreationForm("shrubbery_target");
            std::cout << shrubbery;
            bob.signForm(shrubbery);
            bob.executeForm(shrubbery);
            
            std::cout << "\n=== ROBOTOMY FORM TEST ===" << std::endl;
            RobotomyRequestForm robotomy = RobotomyRequestForm("robotomy_target");
            std::cout << robotomy;
            bob.signForm(robotomy);
            std::cout << "\nAttempt 1:" << std::endl;
            bob.executeForm(robotomy);
            std::cout << "\nAttempt 2:" << std::endl;
            bob.executeForm(robotomy);
            std::cout << "\nAttempt 3:" << std::endl;
            bob.executeForm(robotomy);
            std::cout << "\nAttempt 4:" << std::endl;
            bob.executeForm(robotomy);
            
            std::cout << "\n=== PRESIDENTIAL PARDON FORM TEST ===" << std::endl;
            PresidentialPardonForm pardon = PresidentialPardonForm("pardon_target");
            std::cout << pardon;
            bob.signForm(pardon);
            bob.executeForm(pardon);
        }
        catch (std::exception& e) {
            std::cout << e.what();
        }     
    }

    std::cout << "\n=== GRADE TOO LOW TO SIGN FORM ===" << std::endl;
    {
        try {
            Bureaucrat bob = Bureaucrat("bob", 146);
            std::cout << bob;
            
            ShrubberyCreationForm shrubbery = ShrubberyCreationForm("shrubbery_target");
            std::cout << shrubbery;
            
            bob.signForm(shrubbery);
        }
        catch (std::exception& e) {
            std::cout << e.what();
        }
    }

    std::cout << "\n=== GRADE TOO LOW TO EXECUTE FORM ===" << std::endl;
    {
        try {
            Bureaucrat bob = Bureaucrat("bob", 138);
            std::cout << bob;
            
            ShrubberyCreationForm shrubbery = ShrubberyCreationForm("shrubbery_target");
            std::cout << shrubbery;
            
            bob.signForm(shrubbery);
            bob.executeForm(shrubbery);

        }
        catch (std::exception& e) {
            std::cout << e.what();
        }
    }

    std::cout << "\n=== FORM NOT SIGNED ===" << std::endl;
    {
        try {
            Bureaucrat bob = Bureaucrat("bob", 1);
            std::cout << bob;
            
            ShrubberyCreationForm shrubbery = ShrubberyCreationForm("shrubbery_target");
            std::cout << shrubbery;
            
            bob.executeForm(shrubbery);

        }
        catch (std::exception& e) {
            std::cout << e.what();
        }
    }
    
    std::cout << "\n=== FORM ALREADY SIGNED ===" << std::endl;
    {
        try {
            Bureaucrat foo("foo", 1);
            Bureaucrat bar("bar", 1);
            ShrubberyCreationForm shrubbery("shrubbery_target");
            
            foo.signForm(shrubbery);
            foo.executeForm(shrubbery);
            bar.signForm(shrubbery);
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
    {
        try {
            Bureaucrat bob("bob", 1);
            
            ShrubberyCreationForm original("shrubbery_target");
            bob.signForm(original);
            std::cout << original;
            
            ShrubberyCreationForm copy(original);
            std::cout << copy;
            
            bob.executeForm(original);  // Should succeed
            bob.executeForm(copy);      // Should fail - unsigned
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    return (0);
}