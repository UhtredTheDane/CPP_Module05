/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:53:41 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 16:48:58 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	public:
		Form(void);
		~Form(void);
		Form(Form const& toCopy);
		Form(std::string const& name, int const grade_to_sign, int const grade_to_exec);
		Form& operator=(Form const& toAffect);
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		bool getIsSigned(void) const;
		std::string const& getName(void) const;
		void beSigned(Bureaucrat& b);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class IsAlreadySigned: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const name;
		bool is_signed;
		int const grade_to_sign;
		int const grade_to_exec;
		
};

std::ostream& operator<<(std::ostream &flux, Form const& b);

#endif
