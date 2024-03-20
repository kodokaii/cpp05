/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 23:56:07 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const &other __attribute__((unused)))
{
}

Intern::~Intern(void)
{
}

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm	*form;

	if (name == SHRUBBERY_FORM_NAME)
		form = new ShrubberyCreationForm(target);
	else if (name == ROBOTOMY_REQUEST_FORM_NAME)
		form = new RobotomyRequestForm(target);
	else if (name == PRESIDENTIAL_PARDON_FORM_NAME)
		form = new PresidentialPardonForm(target);
	else
		form = NULL;
	if (form)
		std::cout << "Intern creates " << name << std::endl;
	else
		std::cout << "Intern could not create " << name << " : Name not recognized" << std::endl;
	return (form);
}

Intern	&Intern::operator=(Intern const &other __attribute__((unused)))
{
	return (*this);
}
