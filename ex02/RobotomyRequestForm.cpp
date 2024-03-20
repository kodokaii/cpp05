/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 23:40:37 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):	AForm(ROBOTOMY_REQUEST_FORM_NAME, 72, 45),
																			target(target)
{
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):	AForm(other),
																					target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void					RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy has failed" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	*static_cast<AForm *>(this) = other;
	this->target = other.target;
	return (*this);
}
