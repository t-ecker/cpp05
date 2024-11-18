/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:49:11 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:49:12 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
		std::cout << "creating Ben" << std::endl;
        Bureaucrat a(0, "Ben");
		std::cout << "creating Tim" << std::endl;
        Bureaucrat c(150, "Tim");

		std::cout << "creating f1" << std::endl;
        Form f1("fm1", 0, 0);
		std::cout << "creating f2" << std::endl;
        Form f2("fm2", 150, 150);
        std::cout << std::endl;

        std::cout << "  -Info-" << std::endl;
        std::cout << a << std::endl;
        std::cout << c << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        
        std::cout << std::endl;

        a.signForm(f1);
        std::cout << f1 << std::endl;

        std::cout << std::endl;
        
        c.signForm(f1);
        std::cout << f1 << std::endl;

        std::cout << std::endl;

		std::cout << "creating f3" << std::endl;
        Form f3("f3", 160, 0);
    }
    catch(std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
