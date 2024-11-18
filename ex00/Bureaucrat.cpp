/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:14 by tecker            #+#    #+#             */
/*   Updated: 2024/11/18 12:23:15 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade too Low!");
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}
int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

Bureaucrat::Bureaucrat()
	:	_name("no-name"), _grade(150)
{
}

Bureaucrat::Bureaucrat(int grade, std::string name)
	:	_name(name), _grade(grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	:	_name(src.getName()), _grade(src.getGrade())
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		_grade = src.getGrade();
	return (*this);
}

void Bureaucrat::increment(void)
{
	if (_grade - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement(void)
{
	if (_grade + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat)
{
	os << Bureaucrat.getName() << " | grade: " << Bureaucrat.getGrade();
    return (os);
}