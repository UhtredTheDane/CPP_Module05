/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:54:32 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/12 17:49:55 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern's default constructor called" << std::endl;
}

Intern::Intern(Intern const& toCopy)
{
	std::cout << "Intern's copy constructor called" << std::endl;
	(void) toCopy;
}

Intern& Intern::operator=(Intern const& toAffect)
{
	std::cout << "Intern's copy assignement operator called" << std::endl;
	(void) toAffect;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern's destructor called" << std::endl;
}

AForm* Intern::createShrubberyForm(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyForm(std::string &target)
{

	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialForm(std::string &target)
{

	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const& form_type, std::string &target)
{
	std::string form_types[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm* (Intern::*forms_ptr[3])(std::string&) = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};
	int i;
	for (i = 0; i < 3; ++i)
	{
		if (form_type == form_types[i])
			return ((this->*forms_ptr[i])(target));
	}
	if (i == 3)
		throw (Intern::FormDoesntExistException());
	return (NULL);
}

const char *Intern::FormDoesntExistException::what(void) const throw()
{
	return ("This type form doesn't exist");
}
