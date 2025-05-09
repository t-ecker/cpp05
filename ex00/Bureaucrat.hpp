/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:18 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:23:19 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string.h>
#include <iostream>

#define MIN_GRADE	150
#define MAX_GRADE	0

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		std::string getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat);

#endif