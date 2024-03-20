/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 16:08:04 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

char const	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Form::Form(std::string const &name, int signGrade, int execGrade, bool sign):	name(name),
																				signGrade(signGrade),
																				execGrade(execGrade),
																				sign(sign)
{
	if (signGrade < MAX_GRADE)
		throw (Form::GradeTooHighException());
	if (MIN_GRADE < signGrade)
		throw (Form::GradeTooLowException());
	if (execGrade < MAX_GRADE)
		throw (Form::GradeTooHighException());
	if (MIN_GRADE < execGrade)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const &other):	name(other.name),
								signGrade(other.signGrade),
								execGrade(other.execGrade),
								sign(other.sign)
{
}

Form::~Form(void)
{
}

void				Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->sign = true;
}

std::string const	&Form::getName(void) const
{
	return (this->name);
}

bool				Form::getSigned(void) const
{
	return (this->sign);
}

int					Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int					Form::getExecGrade(void) const
{
	return (this->execGrade);
}

Form	&Form::operator=(Form const &other)
{
	this->sign = other.sign;
	return (*this);
}

std::ostream& operator<<(std::ostream& flux, const Form &form)
{
	flux << "form " << form.getName() << std::endl
	<< "is signed : " << form.getSigned() << std::endl
	<< "minimum grade to sign : " << form.getSignGrade() << std::endl
	<< "minimum grade to execute : " << form.getExecGrade();
	return (flux);
}
