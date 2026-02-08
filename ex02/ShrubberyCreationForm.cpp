/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:09:42 by csavreux          #+#    #+#             */
/*   Updated: 2026/02/08 18:44:42 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("generic_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream   file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not create file");

    file << "     _-_\n"
         << "    /~~   ~~\\               _-_\n"
         << " /~~         ~~\\        /~~   ~~\\\n"
         << "{               }    /~~         ~~\\\n"
         << " \\  _-     -_  /    {               }\n"
         << "   ~  \\\\ //  ~       \\  _-     -_  /\n"
         << "_- -   | | _- _        ~  \\\\ //  ~\n"
         << "  _ -  | |   -_     - _ -  | | _- _-\n"
         << "      // \\\\               // \\\\\n";

    file.close();
}
