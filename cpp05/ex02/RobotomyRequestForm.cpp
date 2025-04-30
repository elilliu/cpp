#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy), _target(copy._target){}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();

	if (this->_execGrade < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << "DddddrrrrrRRRRrrrrrrrr\n";

	std::srand(std::time(0));
	int	random_number = std::rand() % 2;

	if (random_number == 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
