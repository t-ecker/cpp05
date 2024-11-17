#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string.h>
#include <iostream>

#include "AForm.hpp"

#define MIN_GRADE	150
#define MAX_GRADE	0

class AForm;


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
		void signForm(AForm &f);
		void executeForm(AForm const &f);

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