/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:49:01 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 13:38:20 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:	_name("no-name"), _grade_to_exec(0), _grade_to_sign(0), _signed(0)
{
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec)
	: _name(name), _grade_to_exec(grade_to_exec), _grade_to_sign(grade_to_sign), _signed(0)

{
	if (grade_to_exec < MAX_GRADE || grade_to_sign < MAX_GRADE)
		throw Form::GradeTooLowException();
	else if (grade_to_exec > MIN_GRADE || grade_to_sign > MIN_GRADE)
		throw Form::GradeTooHighException();
}
Form::Form(const Form &src)
	:	_name(src.getName()), _grade_to_exec(src.getGradeToExec()), _grade_to_sign(src.getGradeToSign()), _signed(src.getSigned())
{
}
Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		_signed = src.getSigned();
	}
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName(void) const
{
	return (_name);
}

int Form::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int Form::getGradeToExec(void) const
{
	return (_grade_to_exec);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	else
		_signed = 1;
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("(Form) Grade too high");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("(Form) Grade too low");
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
	os << Form.getName() << " | sign status: " << Form.getSigned() << " | Grade to sign: " << Form.getGradeToSign() << " | Grade to execute: " << Form.getGradeToExec();
    return (os);
}
