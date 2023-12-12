/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:54:26 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/12 17:49:12 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const& toCopy);
		~Intern(void);
		Intern& operator=(Intern const& toAffect);
		AForm* createShrubberyForm(std::string &target);
		AForm* createRobotomyForm(std::string &target);
		AForm* createPresidentialForm(std::string &target);
		AForm* makeForm(std::string const& form_type, std::string &target);		

		class FormDoesntExistException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#endif
