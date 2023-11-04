/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:02:45 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/04 18:49:20 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iosteam>
# include <exception>

class BureauCrat
{
	public:
		BureauCrat(void);
		~BureauCrat(void);
		BureauCrat(BureauCrat const& toCopy);
		BureauCrat(std::string const& name, int grade);
		BureauCrat& operator=(BureauCrat const& toAffect);
		std::string const& getName() const;
		int getGrade() const;

	private:
		int grade;
		std:string const name;
		
		class	GradeTooHighException: public exception
		{
			public:	
				virtual const char *what() const throw();
		}
		
		class	GradeTooLowException: public exception
		{
			public:
				virtual const char *what() const throw();
		}
}

#endif
