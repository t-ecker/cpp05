/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:55:14 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:55:15 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "creating Ben" << std::endl;
    Bureaucrat a(5, "Ben");

    std::cout << "creating Intern" << std::endl;
    Intern I1;
    std::cout << std::endl;

    AForm *f1;
    f1 = I1.makeForm("asd", "asd");
    std::cout << std::endl;
    f1 = I1.makeForm("Robotomy Request", "Pia");
    // f1 = I1.makeForm("shrubbery creation", "Home");
    // f1 = I1.makeForm("presidential pardon", "Pia");
    std::cout << std::endl;

    if (f1)
    {
        a.signForm(*f1);
        a.executeForm(*f1);
        delete f1;
    }

    std::cout << std::endl;
    return 0;
}
