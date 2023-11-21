/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:36:02 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/21 18:06:49 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
# include "Bureaucrat.hpp"

BureauCrat::BureauCrat(void)
	:name("Michael Scott"), 
	grade(1)
{
	std::cout << "BureauCrat's default constructor called" << std::endl;
}

BureauCrat::BureauCrat(std::string const& name, int grade)
	:name(name)
{
	std::cout << "BureauCrat's constructor called" << std::endl;
	if (grade < 1)
		throw (BureauCrat::GradeTooHighException());
	else if (grade > 150)
		throw (BureauCrat::GradeTooLowException());
	this->grade = grade;
}

BureauCrat::BureauCrat(BureauCrat const& toCopy)
{
	std::cout << "BureauCrat's copy constructor called" << std::endl;
	*this = toCopy;
}

BureauCrat& BureauCrat::operator=(BureauCrat const& toAffect)
{
	std::cout << "BureauCrat's copy assignement operator called" << std::endl;
	if (this != &toAffect)
		grade = toAffect.grade;
	return (*this);
}

BureauCrat::~BureauCrat(void)
{
	std::cout << "BureauCrat's destructor called" << std::endl;
}

void BureauCrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this <<  " signed " << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << *this <<  " couldn't signed " << f << " because "
			<< e.what() <<std::endl;	
	}
}

void BureauCrat::executeForm(AForm const& form)
{
	form.execute(*this);
}

std::string const& BureauCrat::getName(void) const
{
	return (name);
}

int BureauCrat::getGrade(void) const
{
	return (grade);
}

void BureauCrat::increment(void)
{
	if (this->grade - 1 < 1)
		throw (BureauCrat::GradeTooHighException());
	--this->grade;
	std::cout << "You have been promoted !" << std::endl;
}

void BureauCrat::decrement(void)
{
	if (this->grade + 1 > 150)
		throw (BureauCrat::GradeTooLowException());
	++this->grade;
	std::cout << "You have been downgrade !" << std::endl;
}

const char *BureauCrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high !");
}

const char *BureauCrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low !");
}

std::ostream &operator<<(std::ostream &flux, BureauCrat const& b)
{
	flux << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (flux);
}
