/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/20 23:49:26 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

		class FormNotSignedException : public std::exception
		{
			public:
				char const	*what() const throw();
		};

							AForm(std::string const &name = "unnamed", int signGrade = MAX_GRADE, int execGrade = MAX_GRADE, bool sign = false);
							AForm(AForm const &other);
		virtual				~AForm(void);
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		std::string const	&getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;
		AForm				&operator=(AForm const &other);
};

std::ostream &operator<<(std::ostream &flux, const AForm &form);
