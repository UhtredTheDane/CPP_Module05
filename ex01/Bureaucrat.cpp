/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:36:02 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/12 16:29:08 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:name("Michael Scott"), 
	grade(1)
{
	std::cout << "Bureaucrat's default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
	:name(name)
{
	std::cout << "Bureaucrat's constructor called" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& toCopy)
	:name(toCopy.name),
	grade(toCopy.grade)
{
	std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& toAffect)
{
	std::cout << "Bureaucrat's copy assignement operator called" << std::endl;
	if (this != &toAffect)
		grade = toAffect.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "BureauCrat's destructor called" << std::endl;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this <<  " signed " << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << *this <<  " couldn't signed " << f.getName() << " because "
			<< e.what() <<std::endl;	
	}
}

std::string const& Bureaucrat::getName(void) const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

void Bureaucrat::increment(void)
{
	if (this->grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	--this->grade;
	std::cout << "You have been promoted !" << std::endl;
}

void Bureaucrat::decrement(void)
{
	if (this->grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	++this->grade;
	std::cout << "You have been downgrade !" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high !");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low !");
}

std::ostream &operator<<(std::ostream &flux, Bureaucrat const& b)
{
	flux << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (flux);
}
