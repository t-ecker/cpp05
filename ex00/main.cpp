/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:22 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:23:23 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
		std::cout << "creating Ben" << std::endl;
        Bureaucrat a(0, "Ben");
        std::cout << a << std::endl;
        try
        {
            std::cout << "Incrementing " << a.getName() << "'s grade..." << std::endl;
            a.increment();
        }
        catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << a << std::endl;

        std::cout << std::endl;

		std::cout << "creating Tim" << std::endl;
        Bureaucrat c(150, "Tim");
        std::cout << c << std::endl;
        try
        {
            std::cout << "Decrementing " << c.getName() << "'s grade..." << std::endl;
            c.decrement();
        }
        catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << c << std::endl;

        std::cout << std::endl;

        std::cout << a << std::endl;
        try
        {
            std::cout << "Decrementing " << a.getName() << "'s grade ..." << std::endl;
            a.decrement();
        }
        catch (std::exception& e)
        {
  		      std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << a << std::endl;

        std::cout << std::endl;

		std::cout << "creating Sam" << std::endl;
        Bureaucrat b(152, "Sam");
    }
    catch(std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
