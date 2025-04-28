#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(75){};

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	(*this) = copy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (out);
}

Bureaucrat::~Bureaucrat(){}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	int	tmp = this->_grade;

	tmp--;
	if (tmp < 1)
		throw GradeTooHighException();
	else
		this->_grade = tmp;
}

void	Bureaucrat::decrementGrade()
{
	int	tmp = this->_grade;

	tmp++;
	if (tmp > 150)
		throw GradeTooLowException();
	else
		this->_grade = tmp;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}
