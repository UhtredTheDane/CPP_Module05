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
	: AForm("Robotomy", 72, 45)
{
	this->target = "Unknow";
	std::cout << "RobotomyRequestForm's default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string& target)
	: AForm("Robotomy", 72, 45)
{
	if (!target.empty())
		this->target = target;
	else
		this->target = "Unknow";
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
	if (this != &toAffect)
		this->target = toAffect.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	try
	{
		this->checkGradeToExec(executor);
		std::cout << "DRRRR DRRRR DRRRR DRRRR... " << this->target << "has been robotomized !" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
