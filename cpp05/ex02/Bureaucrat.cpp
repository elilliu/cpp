#include "Bureaucrat.hpp"


//   CONSTRUCTORS   //

Bureaucrat::Bureaucrat(){}

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


//   OPERATORS   //

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


//   DESTRUCTOR   //

Bureaucrat::~Bureaucrat(){}


//   GETTERS   //

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}


//   FUNCTIONS   //

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

void	Bureaucrat::signForm(AForm& form) const
{
	if (form.getSigned() == true)
	{
		std::cout << form.getName() << " is already signed." << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}

	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << '\n';
	}
}


//   EXCEPTIONS   //

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The bureaucrat's grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The bureaucrat's grade is too low");
}
