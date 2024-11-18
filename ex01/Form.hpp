/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:49:06 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:49:07 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int _grade_to_exec;
        const int _grade_to_sign;
        bool _signed;
    
    public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_exec);
		Form(const Form &src);
        Form &operator=(const Form &src);
		~Form();

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
        bool getSigned(void) const;
        void beSigned(const Bureaucrat &b); 

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const noexcept;
		};
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif