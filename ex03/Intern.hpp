/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:55:09 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:55:10 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string.h>
#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
        Intern &operator=(const Intern &src);
		~Intern();
		AForm *makeForm(std::string name, std::string target);
};

#endif