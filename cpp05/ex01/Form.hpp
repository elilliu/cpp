#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& copy);
		Form&	operator=(const Form& copy);
		~Form();

		class GradeTooHighException: public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char*	what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExcecGrade() const;

		void	beSigned(const Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
