/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:02:45 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/20 17:21:34 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
 
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;
class BureauCrat
{
	public:
		BureauCrat(void);
		~BureauCrat(void);
		BureauCrat(BureauCrat const& toCopy);
		BureauCrat(std::string const& name, int grade);
		BureauCrat& operator=(BureauCrat const& toAffect);
		std::string const& getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void signForm(Form& f);	

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

std::ostream &operator<<(std::ostream &flux, BureauCrat const& b);

#endif
