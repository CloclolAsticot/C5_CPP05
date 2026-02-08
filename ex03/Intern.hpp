/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:12:19 by csavreux          #+#    #+#             */
/*   Updated: 2026/02/08 18:42:38 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern 
{
    public:
        // Constructors / Destructors
        Intern();
        Intern(const Intern& other);
        ~Intern();
        
        Intern& operator=(const Intern& other);

        // Other member functions
        AForm*    makeForm(const std::string& formName, const std::string& target);
};

#endif