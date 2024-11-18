/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:54:46 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 13:39:16 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	:	_name("no-name"), _grade_to_exec(0), _grade_to_sign(0), _signed(0)
{
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec)
	: _name(name), _grade_to_exec(grade_to_exec), _grade_to_sign(grade_to_sign), _signed(0)

{
	if (grade_to_exec < MAX_GRADE || grade_to_sign < MAX_GRADE)
		throw AForm::GradeTooLowException();
	else if (grade_to_exec > MIN_GRADE || grade_to_sign > MIN_GRADE)
		throw AForm::GradeTooHighException();
}
AForm::AForm(const AForm &src)
	:	_name(src.getName()), _grade_to_exec(src.getGradeToExec()), _grade_to_sign(src.getGradeToSign()), _signed(src.getSigned())
{
}
AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		_signed = src.getSigned();
	}
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName(void) const
{
	return (_name);
}

int AForm::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int AForm::getGradeToExec(void) const
{
	return (_grade_to_exec);
}

bool AForm::getSigned(void) const
{
	return (_signed);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw AForm::FormAlreadySignedException();
	else if (b.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	else
		_signed = 1;
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("(AForm) Grade too high");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("(AForm) Grade too low");
}

const char *AForm::FormNotSignedException::what() const noexcept
{
	return ("(AForm) Form not signed");
}

const char *AForm::FormAlreadySignedException::what() const noexcept
{
	return ("(AForm) Form already signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << AForm.getName() << " | sign status: " << AForm.getSigned() << " | Grade to sign: " << AForm.getGradeToSign() << " | Grade to execute: " << AForm.getGradeToExec();
    return (os);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > _grade_to_exec)
		throw AForm::GradeTooHighException();
	else
		exec_form();
}
