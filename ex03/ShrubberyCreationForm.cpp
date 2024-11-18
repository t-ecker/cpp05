/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:56:03 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 13:58:49 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	:	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	:	AForm(src), _target(src.getTarget())
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		AForm::operator=(src); 
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget()	const
{
	return (_target);
}

void ShrubberyCreationForm::exec_form(void) const
{
	std::cout << "printed tree in " << _target + "_shrubbery" << std::endl;
	std::ofstream fileW((_target + "_shrubbery"), std::ios::out | std::ios::trunc);
	if (!fileW.is_open())
	{
		throw std::runtime_error("File creation failed");
	}
	fileW << "       &&& &&  & &&\n"
             "    && &\\/&^& ()|/ &, &&\n"
             "    &\\/(/&/&||/& /_/)_&/_&\n"
             " &() &\\/&|()|/&\\/ % & ()\n"
             "&_\\_&&_\\ |& |&&/&__%_/_& &&\n"
             "&&   && & &| &| /& & % ()& /&&\n"
             " ()&_---()&\\&\\|&&-&&--%---()~\n"
             "     &&     \\|||\n"
             "             |||\n"
             "             |||\n"
             "             |||\n"
             "       , -=-~  .-^- _\n";
	fileW.close();
}
