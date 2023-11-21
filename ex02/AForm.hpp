/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:53:41 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/21 18:10:32 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <string>
class BureauCrat;

class AForm
{
	public:
		AForm(void);
		virtual ~AForm(void);
		AForm(AForm const& toCopy);
		AForm(std::string const& name, int const grade_to_sign, int const grade_to_exec);
		AForm& operator=(AForm const& toAffect);
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		bool getIsSigned(void) const;
		std::string const& getName(void) const;
		void beSigned(BureauCrat const& b);
		void checkGradeToExec(BureauCrat const& executor) const;
		virtual void execute(BureauCrat const& executor) const = 0;

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
		class IsNotSigned: public std::exception
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

std::ostream& operator<<(std::ostream &flux, AForm const& b);

#endif
