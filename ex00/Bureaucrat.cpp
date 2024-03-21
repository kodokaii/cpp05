/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/21 10:57:35 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::Bureaucrat(std::string name, int grade):	name(name),
														grade(grade)
{
	if (grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (MIN_GRADE < grade)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &other):	name(other.name),
													grade(other.grade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

void				Bureaucrat::incrementGrade(void)
{
	if (this->grade <= MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	this->grade--;

}

void				Bureaucrat::decrementGrade(void)
{
	if (MIN_GRADE <= grade)
		throw (Bureaucrat::GradeTooLowException());
	this->grade++;
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& flux, const Bureaucrat &bureaucrat)
{
	flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return flux;
}
