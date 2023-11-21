/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:01 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/21 18:09:22 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon", 25, 5)
{
	this->target = "Unknow";
	std::cout << "PresidentialPardonForm's default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target)
	: AForm("Presidential Pardon", 25, 5)
{
	if (!target.empty())
		this->target = target;
	else
		this->target = "Unknow";
	std::cout << "PresidentialPardonForm's constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& toCopy)
	: AForm(toCopy)
{
	std::cout << "PresidentialPardonForm's copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm's destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& toAffect)
{
	std::cout << "PresidentialPardonForm's copy assignement operator called" << std::endl;
	if (this == &toAffect)
		this->target = toAffect.target;
	return (*this); 
}

void PresidentialPardonForm::execute(BureauCrat const& executor) const
{
	try
	{
		this->checkGradeToExec(executor);
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

