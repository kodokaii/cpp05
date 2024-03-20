/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 22:59:05 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		int const			signGrade;
		int const			execGrade;
		bool				sign;

	public:
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

							Form(std::string const &name = "unnamed", int signGrade = MAX_GRADE, int execGrade = MAX_GRADE, bool sign = false);
							Form(Form const &other);
							~Form(void);
		void				beSigned(const Bureaucrat &bureaucrat);
		std::string const	&getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;
		Form				&operator=(Form const &other);
};

std::ostream &operator<<(std::ostream &flux, const Form &form);
