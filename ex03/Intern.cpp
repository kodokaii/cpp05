/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/21 14:55:26 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


char const	*Intern::formName[] = {	SHRUBBERY_FORM_NAME,
									ROBOTOMY_REQUEST_FORM_NAME,
									PRESIDENTIAL_PARDON_FORM_NAME,
									NULL};

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
	int		formId;

	for (formId = 0; Intern::formName[formId] && Intern::formName[formId] != name; formId++);
	if (Intern::formName[formId])
		std::cout << "Intern creates " << name << std::endl;
	else
		std::cout << "Intern could not create " << name << " : Name not recognized" << std::endl;
	switch (formId)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			return (NULL);
	}
}

Intern	&Intern::operator=(Intern const &other __attribute__((unused)))
{
	return (*this);
}
