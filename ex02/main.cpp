/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:54:08 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:54:09 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        std::cout << "creating Ben" << std::endl;
        Bureaucrat a(137, "Ben");
		std::cout << "creating Tim" << std::endl;
        Bureaucrat c(5, "Tim");
        std::cout << "creating Lars" << std::endl;
        Bureaucrat b(45, "Lars");

		std::cout << "creating f1" << std::endl;
        ShrubberyCreationForm f1("home");
		std::cout << "creating f2" << std::endl;
        RobotomyRequestForm f2("Patient_1");
        std::cout << "creating f3" << std::endl;
        PresidentialPardonForm f3("Pia");
        std::cout << std::endl;

        std::cout << "  -Info-" << std::endl;
        std::cout << a << std::endl;
        std::cout << c << std::endl;
        std::cout << b << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
        
        std::cout << std::endl;

        a.signForm(f1);
        a.executeForm(f1);

        std::cout << std::endl;

        b.signForm(f2);
        b.executeForm(f2);

        std::cout << std::endl;

        c.signForm(f3);
        c.executeForm(f3);

        std::cout << std::endl;

        a.signForm(f3);
        a.executeForm(f3);
    }
    catch(std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
