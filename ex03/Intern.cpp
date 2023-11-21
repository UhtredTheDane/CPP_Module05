/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:54:32 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/21 18:45:09 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern's default constructor called" << std::endl;
}

Intern::Intern(Intern const& toCopy)
{
	std::cout << "Intern's copy constructor called" << std::endl;
}

Intern& Intern::operator=(Intern const& toAffect)
{
	std::cout << "Intern's copy assignement operator called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern's destructor called" << std::endl;
}

ShrubberyCreationForm& Intern::createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

RobotomyRequestForm& Intern::createRobotomyForm(std::string target)
{

	return (new RobotomyRequestForm(target));
}

PresidentialPardonForm& Intern::createPresidentialForm(std::string target)
{

	return (new PresidentialPardonForm(target));
}

AForm& Intern::makeForm(std::string const& form_type, std::string target)
{
	std::string form_types = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	void (Intern::*forms_ptr[])(AForm&) = {&Intern::ShrubberyCreationForm, &Intern::RobotomyRequestForm, &Intern::PresidentialPardonForm};

	for (int i = 0; i < 3; ++i)
	{
		if (form_type == form_types[i])
			return ((this->*forms_ptr[i])());
	}
	if (i == 3)
		throw ();	
}

const char *Intern::FormDoesntExistException::what(void) const throw()
{
	return ("This type form doesn't exist");
}
