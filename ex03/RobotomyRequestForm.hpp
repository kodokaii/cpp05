/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 23:40:26 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include "AForm.hpp"

#define ROBOTOMY_REQUEST_FORM_NAME "robotomy request"

class RobotomyRequestForm: public AForm
{
	protected:
		std::string	target;

	public:
								RobotomyRequestForm(std::string const &target = "default");
								RobotomyRequestForm(RobotomyRequestForm const &other);
								~RobotomyRequestForm(void);
		void					execute(Bureaucrat const &executor) const;
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
};
