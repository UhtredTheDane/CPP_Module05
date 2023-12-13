/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:53:45 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 17:18:31 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
	: name("Certificate"),
	is_signed(false),
	grade_to_sign(1),
	grade_to_exec(1)
{
	std::cout << "AForm's default constructor called" << std::endl;
}

AForm::AForm(AForm const& toCopy)
	: name(toCopy.name),
	is_signed(toCopy.is_signed),
	grade_to_sign(toCopy.grade_to_sign),
	grade_to_exec(toCopy.grade_to_exec)
{
	std::cout << "AForm's copy constructor called" << std::endl;
}

AForm::AForm(std::string const& name, int const grade_to_sign, int const grade_to_exec)
	: name(name),
	grade_to_sign(grade_to_sign),
	grade_to_exec(grade_to_exec)
{
	this->is_signed = false;
	std::cout << "AForm's constructor called" << std::endl;
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw (AForm::GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm(void)
{
	std::cout << "AForm's destructor called" << std::endl;
}

AForm& AForm::operator=(AForm const& toAffect)
{
	std::cout << "AForm's copy assignement operator called" << std::endl;
	if (this != &toAffect)
		this->is_signed = toAffect.is_signed;
	return (*this);
}

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->grade_to_sign)
		throw (AForm::GradeTooLowException());
	else if (this->is_signed)
		throw (AForm::IsAlreadySigned());
	else
		this->is_signed = true;
		
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!this->is_signed)
		throw (AForm::IsNotSigned());
	else if (executor.getGrade() > this->grade_to_exec)
		throw (AForm::GradeTooLowException());
	this->makeExecute();
}

int AForm::getGradeToSign(void) const
{
	return (grade_to_sign);
}

int AForm::getGradeToExec(void) const
{
	return (grade_to_exec);
}

bool AForm::getIsSigned(void) const
{
	return (is_signed);	
}

std::string const& AForm::getName(void) const
{
	return (name);
}

std::ostream& operator<<(std::ostream &flux, AForm const& b)
{
	flux << b.getName() << " needs grade " << b.getGradeToSign() << " for sign and grade "
		<< b.getGradeToExec() << " for execute, it is ";
	if (b.getIsSigned())
		std::cout << "signed";
	else
		std::cout << "not signed";
	return (flux);
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("You grade is too high for this AForm");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("You grade is too low for this AForm");
}

const char* AForm::IsAlreadySigned::what(void) const throw()
{
	return ("it is already signed");
}

const char* AForm::IsNotSigned::what(void) const throw()
{
	return ("it is not signed");
}
