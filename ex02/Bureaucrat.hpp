/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:02:45 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 17:16:20 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
 
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;
class Bureaucrat
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const& toCopy);
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat& operator=(Bureaucrat const& toAffect);
		std::string const& getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void signForm(AForm& f);	
		void executeForm(AForm const& form);

		class	GradeTooHighException: public std::exception
		{
			public:	
				virtual const char *what() const throw();
		};
		
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const name;
		int grade;

};

std::ostream &operator<<(std::ostream &flux, Bureaucrat const& b);

#endif
