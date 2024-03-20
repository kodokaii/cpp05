/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 23:36:14 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):	AForm(SHRUBBERY_FORM_NAME, 145, 137),
																			target(target)
{
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):	AForm(other),
																					target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void					ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		filename(this->target + "_shrubbery");
	std::ofstream	file;

	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	file.open(filename.c_str());
	if (!file.is_open())
		std::cerr << "shrubbery: " << filename << ": " << std::strerror(errno) << std::endl;
	else
		file << ASCII_TREE;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	*static_cast<AForm *>(this) = other;
	this->target = other.target;
	return (*this);
}
