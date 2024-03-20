/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 23:39:03 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PRESIDENTIAL_PARDON_FORM_NAME "presidential pardon"

class PresidentialPardonForm: public AForm
{
	protected:
		std::string	target;

	public:
								PresidentialPardonForm(std::string const &target = "default");
								PresidentialPardonForm(PresidentialPardonForm const &other);
								~PresidentialPardonForm(void);
		void					execute(Bureaucrat const &executor) const;
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);
};
