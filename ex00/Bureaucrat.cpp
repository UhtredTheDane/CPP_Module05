/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:36:02 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/04 18:53:09 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BureauCrat.hpp"

BureauCrat::BureauCrat(void)
{
	std::cout << "Default Constructor called" << std::endl;
	name = "Michael Scott"
	grade = 1;
}

BureauCrat::BureauCrat(std::string const& name, int grade)
	: name(name), grade(grade)
{

}

BureauCrat::~BureauCrat(void)
{	
	std::cout << "Destructor called" << std::endl;
}

BureauCrat::BureauCrat(BureauCrat const& toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

BureauCrat& BureauCrat::operator=(BureauCrat const& toAffect)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &toAffect)
	{
		name = toAffect.name;
		grade = toAffect.grade;
	}
	return (*this);
}

std::string const& BureauCrat::getName() const
{
	return (name);
}

int BureauCrat::getGrade() const
{
	return (grade);
}
