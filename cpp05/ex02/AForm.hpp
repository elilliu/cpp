#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& copy);
		AForm&	operator=(const AForm& copy);
		virtual ~AForm();

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

		class FormNotSignedException: public std::exception
		{
			public:
				const char*	what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExcecGrade() const;

		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif
