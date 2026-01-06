/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:10:26 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/06 16:47:50 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== INIT FORM WITH LIMIT GRADES ===" << std::endl;
    {
        try
        {
            Form foo = Form("foo", 1, 1);
            std::cout << foo;
            Form bar = Form("bar", 150, 150);
            std::cout << bar;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== INIT FORM WITH TOO HIGH GRADE ===" << std::endl;
    {
        try
        {
            Form foo = Form("foo", 0, 1);
            std::cout << foo;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Form bar = Form("bar", 1, 0);
            std::cout << bar;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n=== INIT FORM WITH TOO LOW GRADE ===" << std::endl;
    {
        try
        {
            Form foo = Form("foo", 151, 150);
            std::cout << foo;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Form bar = Form("bar", 150, 151);
            std::cout << bar;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n=== FORM COPY CONSTRUCTOR ===" << std::endl;
    {
        try
        {
            Form original("original", 50, 25);
            Bureaucrat bob("bob", 10);
            bob.signForm(original);
            
            Form copy(original);
            std::cout << "Original: " << original;
            std::cout << "Copy: " << copy;
        }
        catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== SIGNING : SUCCESS + ALREADY SIGNED ===" << std::endl;
    {
        try
        {
            Form foo = Form("foo", 130, 110);
            std::cout << foo;
            Bureaucrat bob = Bureaucrat("bob", 120);
            std::cout << bob;
            bob.signForm(foo);
            std::cout << foo;
            bob.signForm(foo);
            std::cout << foo;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n=== SIGNING : GRADE TOO LOW ===" << std::endl;
    {
        try
        {
            Form foo = Form("foo", 130, 110);
            std::cout << foo;
            Bureaucrat bob = Bureaucrat("bob", 140);
            std::cout << bob;
            bob.signForm(foo);
            std::cout << foo;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return (0);
}