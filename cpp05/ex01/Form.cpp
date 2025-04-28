#include "Form.hpp"


//   CONSTRUCTORS   //

Form::Form(): _name("Default"), _signed(false), _signGrade(75), _execGrade(75){}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade){}


//   OPERATORS   //

Form&	Form::operator=(const Form& copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << "Form name: " << form.getName() << std::endl;

	if (form.getSigned() == false)
	{
		out << "Status: Unsigned" << '\n';
		out << "Signing recquirements: " << form.getSignGrade() << std::endl;
	}

	else
		out << "Status: Signed" << '\n';

	out << "Execution requirements: " << form.getExcecGrade() << std::endl;

	return (out);
}


//   DESTRUCTOR   //

Form::~Form(){}


//   GETTERS   //

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExcecGrade() const
{
	return (this->_execGrade);
}


//   EXCEPTIONS   //

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("The form's grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("The form's grade is too low");
}


//   FUNCTION   //

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_signed = true;
}
