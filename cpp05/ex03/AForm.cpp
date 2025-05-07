#include "AForm.hpp"


//   CONSTRUCTORS   //

AForm::AForm(): _name("Default"), _signed(false), _signGrade(75), _execGrade(75){}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade){}


//   OPERATORS   //

AForm&	AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const AForm& AForm)
{
	out << "Form name: " << AForm.getName() << std::endl;

	if (AForm.getSigned() == false)
	{
		out << "Status: Unsigned" << '\n';
		out << "Signing recquirements: " << AForm.getSignGrade() << std::endl;
	}

	else
		out << "Status: Signed" << '\n';

	out << "Execution requirements: " << AForm.getExcecGrade() << std::endl;

	return (out);
}


//   DESTRUCTOR   //

AForm::~AForm(){}


//   GETTERS   //

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExcecGrade() const
{
	return (this->_execGrade);
}


//   EXCEPTIONS   //

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("The form's grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("The form's grade is too low");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("The form isn't signed");
}


//   FUNCTION   //

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_signed = true;
}
