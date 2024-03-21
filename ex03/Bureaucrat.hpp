/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/21 10:58:26 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
		public:
			char const	*what() const throw(); 
	};

	class GradeTooLowException : public std::exception
	{
		public:
			char const	*what() const throw();
	};

	protected:
		std::string	const	name;
		int					grade;

	public:
							Bureaucrat(std::string name = "unnamed", int grade = MIN_GRADE);
							Bureaucrat(Bureaucrat const &other);
							~Bureaucrat(void);
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm& form);
		void				executeForm(const AForm &form);
		std::string const	&getName(void) const;
		int					getGrade(void) const;
		Bureaucrat			&operator=(Bureaucrat const &other);
};

std::ostream& operator<<(std::ostream& flux, const Bureaucrat &bureaucrat);
