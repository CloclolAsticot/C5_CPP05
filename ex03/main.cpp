/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:10:26 by csavreux          #+#    #+#             */
/*   Updated: 2026/02/08 18:42:23 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Intern.hpp"

int main()
{
    srand(time(NULL)); //generates the seed used by rand() for the Robotomization request form
    
    Intern someRandomIntern;
    
    std::cout << "\n=== CREATION OF ALL TYPES OF FORM ===" << std::endl;
    
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
        std::cout << *rrf;
    
    AForm* sf;
    sf = someRandomIntern.makeForm("shrubbery creation", "file");
    if (sf)
        std::cout << *sf;

    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "GuiltyGuy");
    if (ppf)
        std::cout << *ppf;

    AForm* unknown;
    unknown = someRandomIntern.makeForm("unknown", "target");
    if (unknown)
        std::cout << *unknown;

    try {
        Bureaucrat boss = Bureaucrat("boss", 1);
        
        std::cout << "\n=== SHRUBBERY FORM TEST ===" << std::endl;
        boss.signForm(*sf);
        boss.executeForm(*sf);
        
        std::cout << "\n=== ROBOTOMY FORM TEST ===" << std::endl;
        boss.signForm(*rrf);
        std::cout << "\nAttempt 1:" << std::endl;
        boss.executeForm(*rrf);
        std::cout << "\nAttempt 2:" << std::endl;
        boss.executeForm(*rrf);
        std::cout << "\nAttempt 3:" << std::endl;
        boss.executeForm(*rrf);
        std::cout << "\nAttempt 4:" << std::endl;
        boss.executeForm(*rrf);
        
        std::cout << "\n=== PRESIDENTIAL PARDON FORM TEST ===" << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }

    if (rrf)
        delete rrf;
    if (sf)
        delete sf;
    if (ppf)
        delete ppf;
    if (unknown)
        delete unknown;
    
    return (0);
}