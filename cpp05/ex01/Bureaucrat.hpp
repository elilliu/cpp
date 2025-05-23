#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat&	operator=(const Bureaucrat& copy);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		
		void	incrementGrade();
		void	decrementGrade();

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

		void	signForm(Form& form) const;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
