#include "Form.hpp"

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

		GradeTooLowException::what() const noexcept