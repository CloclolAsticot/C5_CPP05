/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:10:26 by csavreux          #+#    #+#             */
/*   Updated: 2026/01/04 16:31:19 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
        std::cout << "=== INIT WITH LIMIT GRADES ===" << std::endl;
    {
        try
        {
            Bureaucrat foo = Bureaucrat("foo", 1);
            std::cout << foo;
            Bureaucrat bar = Bureaucrat("bar", 150);
            std::cout << bar;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== INIT WITH TOO HIGH GRADE ===" << std::endl;
    {
        try
        {
            Bureaucrat foo = Bureaucrat("foo", 0);
            std::cout << foo;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n=== INIT WITH TOO LOW GRADE ===" << std::endl;
    {
        try
        {
            Bureaucrat foo = Bureaucrat("foo", 151);
            std::cout << foo;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== INCREMENT GRADE ===" << std::endl;
    {
        try
        {
            Bureaucrat foo = Bureaucrat("foo", 2);
            std::cout << foo;
            foo.incrementGrade();
            std::cout << foo;
            foo.incrementGrade();
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== DECREMENT GRADE ===" << std::endl;
    {
        try
        {
            Bureaucrat foo = Bureaucrat("foo", 149);
            std::cout << foo;
            foo.decrementGrade();
            std::cout << foo;
            foo.decrementGrade();
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
    {
        try
        {
            Bureaucrat original("original", 1);
            Bureaucrat copy(original);
            std::cout << "Original: " << original;
            std::cout << "Copy: " << copy;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;
    {
        try
        {
            Bureaucrat bar("bar", 1);
            std::cout << bar;
            {
                Bureaucrat foo("foo", 150);
                bar = foo;
            }
            std::cout << bar;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    return (0);
}