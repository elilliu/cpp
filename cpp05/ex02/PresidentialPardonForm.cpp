#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy), _target(copy._target){}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();

	else if (this->_execGrade < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();

	std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}
