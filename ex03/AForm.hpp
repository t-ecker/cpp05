/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:54:50 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 13:00:58 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const int _grade_to_exec;
        const int _grade_to_sign;
        bool _signed;
    
    public:
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_exec);
		AForm(const AForm &src);
        AForm &operator=(const AForm &src);
		virtual ~AForm();

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
        bool getSigned(void) const;
        void beSigned(const Bureaucrat &b); 
		void execute(Bureaucrat const & executor) const;
		virtual void exec_form(void) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const noexcept;
		};

		class FormAlreadySignedException : public std::exception
		{
			public:
				const char *what() const noexcept;
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif