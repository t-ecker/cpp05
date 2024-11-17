#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	:	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	:	AForm(src), _target(src.getTarget())
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		AForm::operator=(src); 
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget()	const
{
	return (_target);
}

void RobotomyRequestForm::exec_form(void) const
{
	std::srand(std::time(nullptr));
	std::cout << "brum brum!" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "the robotomy of " << _target << " failed!" << std::endl;
}