/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:56:32 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 17:19:32 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy", 72, 45),
	target("Unknow")
{
	std::cout << "RobotomyRequestForm's default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: AForm("Robotomy", 72, 45),
	target(target)
{
	std::cout << "RobotomyRequestForm's constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& toCopy)
	: AForm(toCopy)
{
	std::cout << "RobotomyRequestForm's copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm's default constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& toAffect)
{
	std::cout << "RobotomyRequestForm's copy assignement operator called" << std::endl;
	(void) toAffect;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	try
	{
		this->checkGradeToExec(executor);
		std::cout << "DRRRR DRRRR DRRRR DRRRR... ";
		if (std::rand() % 2)
			std::cout << this->target << " has been robotomized !" << std::endl;
		else
			std::cout << "The robotomized on " << this->target << " has been fail !" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
