#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy), _target(copy._target){}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();

	if (this->_execGrade < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();

	std::ofstream	file;
	std::string		fileName = this->_target + "_shrubbery";

	file.open(fileName.c_str());
	file << "							# #### ####\n\
            ### \\/#|### |/####\n\
           ##\\/#/ \\||/##/_/##/_#\n\
         ###  \\/###|/ \\/ # ###\n\
       ##_\\_#\\_\\## | #/###_/_####\n\
      ## #### # \\ #| /  #### ##/##\n\
       __#_--###`  |{,###---###-~\n\
                 \\ }{\n\
                  }}{\n\
                  }}{\n\
                  {{}\n\
            , -=-~{ .-^- _" << std::endl;
	file.close();
}
