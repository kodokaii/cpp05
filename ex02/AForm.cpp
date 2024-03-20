/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 23:22:06 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

char const	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

char const	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

AForm::AForm(std::string const &name, int signGrade, int execGrade, bool sign):	name(name),
													signGrade(signGrade),
													execGrade(execGrade),
													sign(sign)
{
	if (signGrade < MAX_GRADE)
		throw (AForm::GradeTooHighException());
	if (MIN_GRADE < signGrade)
		throw (AForm::GradeTooLowException());
	if (execGrade < MAX_GRADE)
		throw (AForm::GradeTooHighException());
	if (MIN_GRADE < execGrade)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &other):	name(other.name),
									signGrade(other.signGrade),
									execGrade(other.execGrade),
									sign(other.sign)
{
}

AForm::~AForm(void)
{
}

void				AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->sign = true;
}

std::string const	&AForm::getName(void) const
{
	return (this->name);
}

bool				AForm::getSigned(void) const
{
	return (this->sign);
}

int					AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int					AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

AForm	&AForm::operator=(AForm const &other)
{
	this->sign = other.sign;
	return (*this);
}

std::ostream& operator<<(std::ostream& flux, const AForm &form)
{
	flux << "form " << form.getName() << std::endl
	<< "is signed : " << form.getSigned() << std::endl
	<< "minimum grade to sign : " << form.getSignGrade() << std::endl
	<< "minimum grade to execute : " << form.getExecGrade();
	return (flux);
}
