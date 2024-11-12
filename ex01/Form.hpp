#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
    
    public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_exec, bool signed);
		Form(const Form &src);
        Form &operator=(const Form &src);
		~Form();

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
        bool getSigned(void);
        void beSigned(const Bureaucrat &b)

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

std::ostream &operator<<(std::ostream &os, const Form &Bureaucrat);

#endif