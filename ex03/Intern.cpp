/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:55:05 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:55:06 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}


Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return *this;
	return *this;
}


Intern::~Intern()
{
}
AForm *CreatePresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *CreateShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *CreateRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string options[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    AForm *(*operations[3])(std::string) = {CreateRobotomy, CreateShrubbery, CreatePresidentialPardon};
	std::string lowerName = name;
	for (char &c : lowerName)
		c = std::tolower(c);
    for(int i = 0; i < 3; i++)
    {
        if (options[i] == lowerName)
		{
			std::cout << "Intern creates " << name << std::endl;
           	return (operations[i])(target);
		}
    }

	std::cout << "Intern couldn't create " << name << ". Name unknown!"<< std::endl;
	return (nullptr);
}